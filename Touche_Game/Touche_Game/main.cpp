#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include "GameStateManager.h"
#include "Renderer.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char * TITLE = "Touche";

bool quit = false;

bool init();
void gameLoop();
void update();
void render();
void close();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

SDL_Event event;

Camera camera;
Renderer renderer;

GameStateManager gsm;

int main(int argc, char* args[])
{
	if(init()){
		gameLoop();

		close();
	}
	return 0;
}

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{		
			if(!(renderer.init(window)))
			{
				printf("Renderer could not be initialized.");
				return false;
			}

			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			
			camera.init(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			gsm.initManager();
			printf("GSM has been initialized.\n");
			gsm.initStates(&renderer, &camera);
			printf("GS have been initialized. \n");

			return true;
		}
	}
}

void gameLoop() 
{
	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	double msPerUpdate = 1000/100;

	int frames = 0;
	int updates = 0;

	double delta = 0;
	
	std::chrono::high_resolution_clock::time_point markTime = std::chrono::high_resolution_clock::now();

	while(!gsm.shouldQuit())
	{
		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = now - lastTime;
		delta += (duration.count()) / msPerUpdate;
		lastTime = now;
		
		while (delta >= 1) {
			updates++;
			update();
			delta -= 1;
		}

		frames++;
		render();

		std::chrono::high_resolution_clock::time_point totalTimePoint = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> totalTimeDur = totalTimePoint - markTime;
		if (totalTimeDur.count() >= 1000)
		{
			markTime = std::chrono::high_resolution_clock::now();
			printf("UPS:%d FPS:%d\n", updates, frames);
			updates = 0;
			frames = 0;
		}
	}
}

void update()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			gsm.setQuit(true);
		}
		else
		{
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			{
				if (gsm.isPaused())
				{
					gsm.resume();
				}
				else
				{
					gsm.pause();
				}
			}
			else
			{
				gsm.input(&event);
			}
		}
	}

	gsm.update();

}

void render() 
{
	SDL_RenderClear(renderer.get_SDL_Renderer());
	gsm.render();
	SDL_RenderPresent(renderer.get_SDL_Renderer());
}

void close()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
