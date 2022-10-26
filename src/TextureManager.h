#pragma once
#include <SDL2/SDL.h> 
#include <main.h>
#include <map>



class TextureManager {
public:
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


    static TextureManager* Instance() //정적 멤버함수
    {
        if (s_pInstance == 0)
            s_pInstance = new TextureManager();
        return s_pInstance;
    }

private:
    TextureManager() {} //생성자 public에서 private로 변경
    static TextureManager* s_pInstance; //정적 멤버변수 선언
    std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;
