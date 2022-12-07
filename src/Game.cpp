#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"
#include "HpBar.h"
#include "HpBack.h"
#include "Player.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); // 검은색 배경
            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생성 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }
    // Texture 생성 
    if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/spaceship.png", "spaceship", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/sdlbackground.png", "background", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/Bullet.png", "bullet", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/hpback.png", "hpback", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/hpbar.png", "hpbar", m_pRenderer))
    {
        return false;
    }
    
    m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 2751, 640, "background")));
    m_gameObjects.push_back(new Player(new LoaderParams(50, 200, 128, 82, "spaceship")));
    m_gameObjects.push_back(new Bullet(new LoaderParams(50, 200, 128, 41, "bullet")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(400, 200, 128, 82, "animate")));
    m_gameObjects.push_back(new HpBack(new LoaderParams(0, 410, 376, 65, "hpback")));
    m_gameObjects.push_back(new HpBar(new LoaderParams(0, 410, 376, 65, "hpbar")));

    m_bRunning = true;
    return true;
}

void Game::update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for (int i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}
void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
    TheInputHandler::Instance()->clean();
}
void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}