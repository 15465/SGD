
#ifndef Game_H
#define Game_H

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include "circle.h"
#include "TextureManager.h"
//#include "GameObject.h"

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void GameObjectInit();
	void handleEvents();
	void update();
	void render();
	void clean();
	void move();
	bool running() { return isRunning; }

	

	static SDL_Renderer* renderer;
	static SDL_Event event;

	int circle_radius = 320;
private:
	int cntb = 0;
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Rect srcR, dstR;
	double angle = 0;
};


#endif // !Game_H
