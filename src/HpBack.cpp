#include "Game.h"
#include <SDL2/SDL.h>
#include "HpBack.h"

HpBack::HpBack(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void HpBack::draw()
{
	SDLGameObject::draw();
}

void HpBack::update()
{
	SDLGameObject::update();
	//m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	//m_velocity.setX(-5);
}

void HpBack::clean() {}