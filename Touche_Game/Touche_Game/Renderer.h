#pragma once
#include "Camera.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class Renderer
{
public:
	Renderer();

	SDL_Renderer* renderer;

	bool init(SDL_Window* window);

	SDL_Renderer* get_SDL_Renderer();

	void renderSDLTextureOnScreen(SDL_Texture* renderTexture, int x, int y, int w, int h, SDL_Rect* clip = NULL, double rot = 0.0, SDL_Point* center = NULL, int scaleW = 1, int scaleH = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void renderSDLTexture(SDL_Texture* renderTexture, Camera* c, int x, int y, int w, int h, SDL_Rect* clip = NULL, double rot = 0.0, SDL_Point* center = NULL, int scaleW = 1, int scaleH = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void setLogicalResolution(int width, int height);
	void renderEntity(/*Entity e,*/int scale = 1);
	void renderTerrain(/*Terrain t,*/int scale = 1);
	void renderSDLRectangle(int x, int y, int w, int h, SDL_Color outC = { 0, 0, 0, 255 }, SDL_Color inC = {0xFF, 0xFF, 0xFF, 0xFF}, bool filled = true, int thickness = 5);
	void SetRenderScale(double scaleX, double scaleY);

	void renderPawn(int x, int y);

	bool close();

	~Renderer();
};

