#include "GameStateManager.h"

void GameStateManager::initManager()
{
	gameStates.push_back(new DevTestState);
}

void GameStateManager::closeManager()
{

}

void GameStateManager::setState(int s)
{
	currentState = s;
}

bool GameStateManager::initStates(Renderer* r, Camera* c)
{
	for (int i = 0; i < gameStates.size(); i++)
	{
		if (!gameStates.at(i)->init(&currentState, r, c))
		{
			return false;
		}
	}
	return true;
}

bool GameStateManager::closeStates()
{
	for (int i = 0; i < gameStates.size(); i++)
	{
		if (!gameStates.at(i)->close())
		{
			return false;
		}
	}
	return true;
}

void GameStateManager::pause()
{
	paused = true;
}

void GameStateManager::resume()
{
	paused = false;
}

void GameStateManager::input(SDL_Event* event)
{
	gameStates.at(currentState)->input(event);
}

void GameStateManager::update()
{
	if (!paused)
	{
		gameStates.at(currentState)->update();
	}
	else
	{
		gameStates.at(currentState)->pauseUpdate();
	}
}

void GameStateManager::render()
{
	if (!paused)
	{
		gameStates.at(currentState)->render();
	}
	else
	{
		gameStates.at(currentState)->pauseRender();
	}
}

bool GameStateManager::isPaused()
{
	return paused;
}

bool GameStateManager::shouldQuit()
{
	return gameStates.at(currentState)->shouldQuit();
}

void GameStateManager::setQuit(bool q)
{
	gameStates.at(currentState)->setQuit(q);
}