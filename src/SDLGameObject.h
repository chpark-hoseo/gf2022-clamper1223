#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {}
	virtual ~SDLGameObject() {}

protected:

	Vector2D m_position; // ��ġ
	Vector2D m_velocity; // �ӵ�
	Vector2D m_acceleration; // ���ӵ�
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};