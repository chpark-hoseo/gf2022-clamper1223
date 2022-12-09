#include "Game.h"
#include <SDL2/SDL.h>
#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Bullet::draw()
{
	SDLGameObject::draw();
}

void Bullet::update()
{
	SDLGameObject::update();
	m_velocity.setX(20);
	/*
	int bul = 0;
	if (bul <= 5)
	{
		while (bul < 5)
		{
			SDLGameObject::update();
			m_velocity.setX(3);
			bul++;
		}
	}
	
	else
	{
		while (bul < 5)
		{
			clean();
		}
	}
	*/
	
	//m_position.setX(0);
	//얘는 아마 플레이어 위치랑 동기화 시키면 될듯(?)
}

void Bullet::clean() {}