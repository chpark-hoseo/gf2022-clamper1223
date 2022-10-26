//��ó���� �߰� #pragma once
//�� �̰��� ����Ͽ� ��������� �ߺ����� ����� ��ȣ�� ������.
#pragma once
#include <main.h>
#include "TextureManager.h"

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
	SDL_Texture* m_pTexture;

<<<<<<< HEAD
	SDL_Window* m2_pWindow;
	SDL_Renderer* m2_pRenderer;
	bool m2_bRunning;
	SDL_Texture* m2_pTexture;

=======
    int x;
	int y;
    
>>>>>>> ba4ecc43a88c22b436bc7918f0199823ea9a59d9
	// ���� TextureManager m_textureManager;
	int m_currentFrame;
};
