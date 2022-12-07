#include "Game.h"
#include <SDL2/SDL.h>
#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Bullet::draw()
{
	SDLGameObject::draw();
}

void Bullet::update()
{
	SDLGameObject::update();
	//m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	m_velocity.setX(5);
	
}

void Bullet::clean() {}