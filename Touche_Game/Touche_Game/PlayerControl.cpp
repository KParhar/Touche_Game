#include "PlayerControl.h"

void PlayerControl::input(SDL_Event* e, Transform* t)
{
	if (e->type == SDL_KEYDOWN)
	{
		if (e->key.keysym.sym == SDLK_w)
		{
			(t)->move(0, -2);
		}

		if (e->key.keysym.sym == SDLK_s)
		{
			(t)->move(0, 2);
		}

		if (e->key.keysym.sym == SDLK_a)
		{
			(t)->move(-2, 0);
		}

		if (e->key.keysym.sym == SDLK_d)
		{
			(t)->move(2, 0);
		}
	}
}