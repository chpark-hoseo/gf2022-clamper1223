#pragma once
#include <main.h>
SDL_Texture* m_pTexture;

// ���� �簢��
SDL_Rect m_sourceRectangle;

// ��� �簢��
SDL_Rect m_destinationRectangle;

typedef struct SDL_Rect
{
	int x, y;
	int w, h;
} SDL_Rect;