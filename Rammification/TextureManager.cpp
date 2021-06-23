#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Texture* Tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return Tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, int angle) {
	SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, angle, NULL, SDL_FLIP_NONE);
}