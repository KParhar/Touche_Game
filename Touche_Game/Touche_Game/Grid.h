#pragma once
#include <SDL.h>
#include <vector>
#include "Pawn.h"

class Grid
{
public:
	static const int gridW = 7;
	static const int gridH = 7;

	Pawn pawns[10];

	SDL_Rect gridSquares[gridH][gridW];
	int gridSW, gridSH;

	void init(int screenW, int screenH);
	SDL_Rect getGridSquare(int y, int x);
	Pawn getPawn(int i);
	int getW();
	int getH();
};

