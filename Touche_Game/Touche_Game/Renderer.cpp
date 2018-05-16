#include "Renderer.h"

Renderer::~Renderer()
{

}

Renderer::Renderer()
{

}

bool Renderer::init(SDL_Window* window) 
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else 
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}
		return true;
	}
	return true;
}

void Renderer::renderSDLTextureOnScreen(SDL_Texture* renderTexture, int x, int y, int w, int h, SDL_Rect* clip, double rot, SDL_Point* center, int scaleW, int scaleH, SDL_RendererFlip flip)
{
	w *= scaleW;
	h *= scaleH;

	SDL_Rect dstRect = { x, y, w, h };

	SDL_RenderCopyEx(renderer, renderTexture, clip, &dstRect, rot, center, flip);
}

void Renderer::renderSDLTexture(SDL_Texture* renderTexture, Camera* c, int x, int y, int w, int h, SDL_Rect* clip, double rot, SDL_Point* center, int scaleW, int scaleH, SDL_RendererFlip flip)
{
	x -= (c->getX());
	y -= (c->getY());

	w *= scaleW;
	h *= scaleH;

	if ((x < c->screenWidth) || (x + w > 0) || (y < c->screenHeight) && (y + h > 0))
	{
		SDL_Rect dstRect = { x, y, w, h };
		SDL_RenderCopyEx(renderer, renderTexture, clip, &dstRect, rot, center, flip);
	}
}

void Renderer::setLogicalResolution(int width, int height)
{
	SDL_RenderSetLogicalSize(renderer, width, height);
}

void Renderer::renderSDLRectangle(int x, int y, int w, int h, SDL_Color outC, SDL_Color inC, bool filled, int thickness)
{
	SDL_Rect renderRect = { x,y,w,h };
	SDL_SetRenderDrawColor(renderer, outC.r, outC.g, outC.b, outC.a);
	SDL_RenderFillRect(renderer, &renderRect);
	if (!filled)
	{
		SDL_SetRenderDrawColor(renderer, inC.r, inC.g, inC.b, inC.a);
		SDL_Rect insideRect = { x + thickness, y + thickness, w - (2 * thickness), h - (2 * thickness) };
		SDL_RenderFillRect(renderer, &insideRect);
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Renderer::SetRenderScale(double scaleX, double scaleY)
{
	SDL_RenderSetScale(renderer, scaleX, scaleY);
}

SDL_Renderer* Renderer::get_SDL_Renderer()
{
	return renderer;
}

bool Renderer::close()
{
	SDL_DestroyRenderer(renderer);
	return true;
}