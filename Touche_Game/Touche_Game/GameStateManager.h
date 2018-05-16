#pragma once
#include "Renderer.h"
#include "GameState.h"
#include "DevTestState.h"
#include <vector>

class GameStateManager
{
public:
	void initManager();
	void closeManager();

	void setState(int s);

	bool initStates(Renderer* r, Camera* c);
	bool closeStates();

	void pause();
	void resume();

	void input(SDL_Event* event);
	void update();
	void render();

	bool isPaused();

	bool shouldQuit();
	void setQuit(bool q);

private:
	std::vector<GameState*> gameStates;
	int currentState;
	bool paused;
};

