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
    
    while(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        while (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            while (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 0, 0, 0, 255);
                break; // 랜더러 생성 실패
            }
            break; // 윈도우 생성 실패
        }
        break; // SDL 초기화 실패
    }
    //texture 생성(교체)
    if (!TheTextureManager::Instance()->load("assets/Assets/pacman.png", "animate", m_pRenderer))
    {
        return false;
    }
    //다른 이미지를 놓는 순간 강제종료
    //if (!TheTextureManager::Instance()->load("assets/Assets/pacmanmaze.png", "animate", m_pRenderer))
    //{
    //    return false;
    //}

    m_bRunning = true;
    return true;
}
void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}
void Game::render()
{
    int x = 0;
    int y = 0;
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("animate", x, y, 100, 100,
        m_pRenderer);
    

    
    SDL_RenderPresent(m_pRenderer);
}
bool Game::running()
{
    char c;
    int x = 0;
    int y = 0;
    //이 방향조작을 어디다 놔야할지 모르겠음
    for (;;) {
        if (_kbhit()) {
            c = _getch();
            if (c == -32) {
                c = _getch();
                switch (c) {
                case LEFT:
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UP:
                    y--;
                    break;
                case DOWN:
                    y++;
                    break;
                }
            }
        }
    }
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