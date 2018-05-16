#pragma once
#include <SDL.h>

class Pawn
{
public:
	int xGrid;
	int yGrid;
	int gridSize;
	bool isRound;
	
	SDL_Rect hitbox;

	void init(int x, int y, int gS, bool r);
};

