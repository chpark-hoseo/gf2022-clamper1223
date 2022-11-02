//#include "SDL.h"
#include <SDL2/SDL.h>
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
	//TextureManager m_textureManager;
	int m_currentFrame;


	// 원본 사각형
	//SDL_Rect m_sourceRectangle;

	// 대상 사각형
	//SDL_Rect m_destinationRectangle;
};