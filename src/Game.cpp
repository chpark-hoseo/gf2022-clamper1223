#include "Game.h"
#include <main.h>
#include <SDL2/SDL_image.h>
#include <conio.h>
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 0, 0, 0, 255);
                //   break; // ������ ���� ����
            }
            //   break; // ������ ���� ����
        }
        //    break; // SDL �ʱ�ȭ ����
    }
    //texture ����(��ü)
    if (!TheTextureManager::Instance()->load("assets/Assets/pacman.png", "animate", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/Assets/pacmanmaze.jpg", "animate2", m_pRenderer))
    {
        return false;
    }


    m_bRunning = true;
    x = y = 0;

    return true;
}
void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("animate2", 0, 0, 1400, 900, m_pRenderer);
    TheTextureManager::Instance()->draw("animate", x, y, 100, 100, m_pRenderer);


    SDL_RenderPresent(m_pRenderer);
}
bool Game::running()
{
    return m_bRunning;
}
void Game::handleEvents()
{
    SDL_Event event;

    //int degree = 0;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            m_bRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                //degree = 0;
                x += 5;
                break;

            case SDLK_LEFT:
                //degree = 180;
                x -= 5;
                break;

            case SDLK_DOWN:
                //degree = 90;
                y += 5;
                break;

            case SDLK_UP:
                //degree = 270;
                y -= 5;
                break;

            default:
                break;
            }
        }
    }
}
void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}