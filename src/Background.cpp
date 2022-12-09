#include "Game.h"
#include <SDL2/SDL.h>
#include "Background.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Background::draw()
{
	SDLGameObject::draw();
}

void Background::update()
{
	SDLGameObject::update();
	//m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	m_velocity.setX(-4);
	if (m_position.getX() <= -4000)
	{
		m_position.setX(0);
	}
}

void Background::clean() {}