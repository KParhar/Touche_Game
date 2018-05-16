#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Transform.h"

class PlayerControl :
	public Component
{
public:
	void PlayerControl::input(SDL_Event* e, Transform* t);
};

