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
    if (m_position.getX() > -60 && m_position.getX() < 580 && m_position.getY() > -20 && m_position.getY() < 440)
    {
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
            m_velocity.setX(4);
        }
        else {
            m_velocity.setX(0);
        }

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
            m_velocity.setX(-4);
        }
        else {
            //m_velocity.setX(0);
        }

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
            m_velocity.setY(-4);
        }
        else {
            m_velocity.setY(0);
        }

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
            m_velocity.setY(4);
        }
        else {
            //m_velocity.setY(0);
        }

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) { //น฿ป็
            //Bullet::SDLGameObject();
        }
    }
    else if(m_position.getX() < -60)
    {
        m_velocity.setX(0);
        m_position.setX(-59);
    }
    else if (m_position.getX() > 580)
    {
        m_velocity.setX(0);
        m_position.setX(579);
    }
    else if (m_position.getY() < -20)
    {
        m_velocity.setY(0);
        m_position.setY(-19);
    }
    else if (m_position.getY() > 440)
    {
        m_velocity.setY(0);
        m_position.setY(439);
    }
}