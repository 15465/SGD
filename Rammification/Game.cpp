#include "Game.h"



Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	//Fullscreen flag
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	isRunning = false;

	//Initialize
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Initialised" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				std::cout << "Renderer Initialised" << std::endl;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				isRunning = true;
			}
		}
	}
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	cnt++;
	std::cout << cnt << std::endl;
	angle++;
	dstR.h = 64;
	dstR.w = 64;
	dstR.x = 400;
	dstR.y = 400;
}

void Game::render() {
	SDL_RenderClear(renderer);
	//stuff to render
	SDL_RenderCopyEx(renderer, playerTex, NULL, &dstR, angle, NULL, SDL_FLIP_NONE);

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}