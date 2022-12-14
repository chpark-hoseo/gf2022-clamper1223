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
	//m_position.setX(0);
	//��� �Ƹ� �÷��̾� ��ġ�� ����ȭ ��Ű�� �ɵ�(?)
}

void Bullet::clean() {}