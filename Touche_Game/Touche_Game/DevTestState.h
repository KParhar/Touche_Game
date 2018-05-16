#pragma once
#include "GameState.h"
#include "Spritesheet.h"
#include "Animation.h"
#include "Entity.h"
#include "Transform.h"
#include "PlayerControl.h"
#include "Grid.h"

class DevTestState :
	public GameState
{
public:
	Grid gameBoard;
	Entity player;
	Spritesheet playerSheet;

	int playerTurn = 0;

	bool init(int* cS, Renderer* r, Camera* c);
	bool close();

	void pauseUpdate();
	void pauseRender();

	void input(SDL_Event* event);
	void update();
	void render();

};

