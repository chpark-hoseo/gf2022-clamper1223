#include <main.h>
#include "GameObject.h"
#include "Game.h"
#include "InputHandler.h"
#include "Bullet.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    //m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    handleInput();
    SDLGameObject::update();
}
void Player::clean() {}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(2);
    } else {
        m_velocity.setX(0);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-2);
    } else {
        //m_velocity.setX(0);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-2);
    } else {
        m_velocity.setY(0);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setY(2);
    } else {
        //m_velocity.setY(0);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) { //�߻�
        //Bullet::SDLGameObject();
    }
}