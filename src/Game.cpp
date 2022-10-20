#include "Game.h"
#include <main.h>
#include <SDL2/SDL_image.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    
    while(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        while (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            while (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 153, 204, 255, 255);
                break; // 랜더러 생성 실패
            }
            break; // 윈도우 생성 실패
        }
        break; // SDL 초기화 실패
    }
    /*
    while (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m2_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        while (m2_pWindow != 0) {
            m2_pRenderer = SDL_CreateRenderer(m2_pWindow, -1, 0);

            while (m2_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m2_pRenderer, 255, 0, 0, 255);
                break; // 랜더러 생성 실패
            }
            break; // 윈도우 생성 실패
        }
        break; // SDL 초기화 실패
    }
    */
    //texture 생성(교체)
    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)) return false;
    //if (!TheTextureManager::Instance()->load("Assets/ground.png", "ground", m2_pRenderer)) return false;

    m_bRunning = true;
    return true;
}
void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    //교체
    // TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}
bool Game::running()
{
    return m_bRunning;
}
void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}
void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}