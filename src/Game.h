//전처리기 추가 #pragma once
//즉 이것을 사용하여 헤더파일을 중복하지 말라는 신호를 보낸다.
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

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};