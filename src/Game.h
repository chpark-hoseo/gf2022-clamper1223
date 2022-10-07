//��ó���� �߰� #pragma once
//�� �̰��� ����Ͽ� ��������� �ߺ����� ����� ��ȣ�� ������.
#pragma once
#include <main.h>

class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();
	/*
	void render2();
	void update2();
	bool running2();
	void handleEvents2();
	void clean2();
	*/
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	SDL_Texture* m_pTexture;

	// ���� �簢��
	SDL_Rect m_sourceRectangle;

	// ��� �簢��
	SDL_Rect m_destinationRectangle;
	/*
	//�߰�-----------------------------

	// ���� �簢��
	SDL_Rect m2_sourceRectangle;

	// ��� �簢��
	SDL_Rect m2_destinationRectangle;
	*/
};
