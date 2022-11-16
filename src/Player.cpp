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
    SDLGameObject::update(); // ← 부모 클래스의 함수 호출 
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_velocity.setX(1); // 등속도 조절
}
void Player::clean() {}