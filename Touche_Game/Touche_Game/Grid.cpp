#include "Grid.h"

void Grid::init(int screenW, int screenH)
{
	gridSW = screenW / gridW;
	gridSH = screenH / gridH;

	for (int y = 0; y < gridH; y++)
	{
		for (int x = 0; x < gridW; x++)
		{
			gridSquares[y][x] = {x*gridSW, y*gridSH, gridSW, gridSH};
		}
	}

	for (int i = 0; i < 5; i++)
	{
		pawns[i].init(screenW, screenH, gridW, true);
		pawns[5+i].init(screenW, screenH, gridW, false);
	}
}

SDL_Rect Grid::getGridSquare(int y, int x)
{
	if (y == 0 || y == gridH - 1)
	{
		if (x > 0 && x < gridW - 1)
		{
			return {-100, -100, 0, 0};
		}
	}
	return gridSquares[y][x];
}

Pawn Grid::getPawn(int i)
{
	return pawns[i];
}

int Grid::getW()
{
	return gridW;
}

int Grid::getH()
{
	return gridH;
}