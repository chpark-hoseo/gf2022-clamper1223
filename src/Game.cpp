#include "Game.h"
#include <main.h>
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    
    while(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        while (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            while (m_pRenderer != 0) {
                SDL_SetRenderDrawColor(
                    m_pRenderer, 255, 255, 255, 255);
                break;
            }
            //else {
            //    return false; // 랜더러 생성 실패
            //}
            break;
        }
        //else {
        //    return false; // 윈도우 생성 실패
        //}
        break;
    }
    //else {
    //    return false; // SDL 초기화 실패
    //}
    //texture 생성
    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/Assets/animate.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    //원본상자(m_sourceRectangle)의 너비/높이 설정 
    SDL_QueryTexture(m_pTexture, NULL, NULL,
        &m_sourceRectangle.w, &m_sourceRectangle.h);

    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;

    //대상상자(m_destinationRectangle)의 너비/높이 설정
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;


    //원본상자/대상상자의 위치 설정
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;
    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;

    SDL_FreeSurface(pTempSurface);
    m_bRunning = true;
    return true;
}
void Game::update()
{

}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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