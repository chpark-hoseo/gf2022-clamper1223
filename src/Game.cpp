#include "Game.h"
#include <main.h>
#include <SDL2/SDL_image.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 0, 0, 0, 255);
             //   break; // 랜더러 생성 실패
            }
         //   break; // 윈도우 생성 실패
        }
    //    break; // SDL 초기화 실패
    }
    //texture 생성(교체)
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
    /*
    while (SDL_PollEvent(&event)) {


        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sy

            {

            case SDLK_LEFT: x -= 5;  break;
hh
            case SDLK_RIGHT:x += 5; break;

            }


        }
    }
    */
    
   
}
void Game::render()
{
    
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("animate", x, y, 100, 100,
        m_pRenderer);
    TheTextureManager::Instance()->draw("animate2", x, y, 100, 100,
        m_pRenderer);

    
    SDL_RenderPresent(m_pRenderer);
}
bool Game::running()
{
    /*
*/
    return m_bRunning;
}
void Game::handleEvents()
{
 

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            m_bRunning = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                x += 5;
                break;

            case SDLK_LEFT:
                x -= 5;
                break;

            case SDLK_DOWN:
                //  ++playerPos.y;
                break;

            case SDLK_UP:
                //  --playerPos.y;
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