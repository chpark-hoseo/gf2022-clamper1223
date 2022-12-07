#include "Game.h"
#include <SDL2/SDL.h>
#include "HpBar.h"

HpBar::HpBar(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void HpBar::draw()
{
	SDLGameObject::draw();
}

void HpBar::update()
{
	SDLGameObject::update();
	//m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	//m_velocity.setX(-5);
}

void HpBar::clean() {}