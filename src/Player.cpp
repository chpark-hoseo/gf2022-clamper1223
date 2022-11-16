#include <main.h>
#include "GameObject.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    SDLGameObject::update(); // �� �θ� Ŭ������ �Լ� ȣ�� 
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_velocity.setX(1); // ��ӵ� ����
}
void Player::clean() {}