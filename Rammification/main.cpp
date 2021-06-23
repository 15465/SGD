#include "SDL.h"
#include <stdio.h>
#include "Game.h"
//#include "circle.h"

void Test() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
}

Game* game = nullptr;

void RunGame() {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Rammification", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running()) {
		frameStart = SDL_GetTicks();


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}
	game->clean();
}

void VelocityTest() {
	double v = 0.0;
	double friction = 10.0;
	double a = 20.0 + friction;
	double drag = 0.0;
	double maxv = 40.0;
	for (int i = 0; i < 60; i++) {
		drag = (v / maxv)*(a-friction);
		v = v + a - drag - friction;
		std::cout << v << std::endl;
	}


}
int main(int arg, char *argv[]) {
	RunGame();
	

	return 0;
}