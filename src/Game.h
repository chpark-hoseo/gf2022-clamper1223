#pragma once
#include <main.h>
SDL_Texture* m_pTexture;

// 원본 사각형
SDL_Rect m_sourceRectangle;

// 대상 사각형
SDL_Rect m_destinationRectangle;

typedef struct SDL_Rect
{
	int x, y;
	int w, h;
} SDL_Rect;