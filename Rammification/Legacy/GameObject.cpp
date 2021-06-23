#include "GameObject.h"
#include "TextureManager.h"
GameObjectClass::GameObjectClass(const char* texturesheet) {
	destRect.x = 300;
	destRect.y = 300;
	objTexture = TextureManager::LoadTexture(texturesheet);
}

void GameObjectClass::Update() {
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 64;
	srcRect.h = 64;
	destRect.w = 64;
	destRect.h = 64;
	angle++;
}

void GameObjectClass::Set(int xpos, int ypos) {
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObjectClass::Render() {
	SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}