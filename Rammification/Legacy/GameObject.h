#pragma once
#ifndef GameObject_H
#define GameObject_H

#include "Game.h"

class GameObjectClass {
public:
	GameObjectClass(const char* texturesheet);
	~GameObjectClass();

	void Set(int xpos, int ypos);
	void Update();
	void Render();
private:
	int angle = 0;
	int xpos = 0;
	int ypos = 0;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

#endif // !GameObject_H
