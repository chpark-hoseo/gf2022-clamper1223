#include "Game.h"
#include <SDL2/SDL.h>
#include "HpBar.h"
#include "Enemy.h"

HpBar::HpBar(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void HpBar::draw()
{
	SDLGameObject::draw();
}

void HpBar::update()
{
	int a = 0;
	SDLGameObject::update();
	
	/*
	if (Player::SDLGameObject::m_position.getX() == Enemy::SDLGameObject::m_position.getX())
	{
		a = a - 94;
		m_position.setX(a);
	}
	*/
}

void HpBar::clean() {}