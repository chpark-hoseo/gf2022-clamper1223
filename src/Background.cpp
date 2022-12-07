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
	//좌표값이 x가 -2271이 되면 되돌아가기
}

void Background::clean() {}