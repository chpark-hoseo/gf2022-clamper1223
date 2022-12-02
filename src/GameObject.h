#pragma once

// #include <SDL2/SDL.h>
#include "LoaderParams.h"

#include <string>
class GameObject {

public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual ~GameObject() {}

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;

	GameObject(const LoaderParams* pParams) {}
};
