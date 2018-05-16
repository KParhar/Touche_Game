#include "DevTestState.h"

bool DevTestState::init(int* cS, Renderer* r, Camera* c)
{
	currentState = cS;
	renderer = r;
	camera = c;

	playerSheet.loadSpritesheet("C:/Users/Kush/Desktop/Project_Andromeda/Project_Andromeda/Project_Andromeda/res/PlayerSpritesheet.png",
		"C:/Users/Kush/Desktop/Project_Andromeda/Project_Andromeda/Project_Andromeda/res/PlayerSpritesheetData.txt", renderer);
	
	player.addComponent("transform", new Transform);
	((Transform*)player.getComponent("transform"))->init(100, 100, 50, 50);
	
	player.addComponent("input", new PlayerControl);

	gameBoard.init(camera->getScreenWidth(), camera->getScreenHeight());

	return true;
}

void DevTestState::pauseUpdate() {}
void DevTestState::pauseRender() {}

void DevTestState::input(SDL_Event* event) 
{
	
}

void DevTestState::update()
{
	
}
void DevTestState::render()
{
	for (int y = 0; y < gameBoard.getH(); y++)
	{
		for (int x = 0; x < gameBoard.getW(); x++)
		{
			SDL_Rect gE = gameBoard.getGridSquare(y, x);
			renderer->renderSDLRectangle(gE.x, gE.y, gE.w, gE.h, { 0xFF, 0xFF, 0xFF, 0xFF }, { 0xCC, 0xCC, 0xCC, 0xFF }, false, 2);
		}
	}
	
}

bool DevTestState::close()
{
	return true;
}