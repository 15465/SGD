#include "Game.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

//GameObjectClass* AI[4];
//GameObjectClass* player;

Manager manager;
auto& playerEntity(manager.addEntity());
auto& playerTwoEntity(manager.addEntity());
auto& AIEntity(manager.addEntity());

Game::Game() {}
Game::~Game() {}

bool multiplayer = false;

Vector2D tempCollisionHandler(Vector2D t1, Vector2D t2) {
	Vector2D result;
	result.x = (t1.x + t2.x);
	result.y = (t1.y + t2.y);
	return result;
}

void Game::GameObjectInit() {
	playerEntity.addComponent<TransformComponent>();
	playerEntity.getComponent<TransformComponent>().position.x = 200.0f;
	playerEntity.getComponent<TransformComponent>().position.y = 200.0f;
	playerEntity.addComponent<SpriteComponent>("assets/Baran.png");
	playerEntity.addComponent<KeyboardController>();
	playerEntity.addComponent<Goat>(true);

	if (multiplayer) {
		playerTwoEntity.addComponent<TransformComponent>();
		playerTwoEntity.getComponent<TransformComponent>().position.x = 400.0f;
		playerTwoEntity.getComponent<TransformComponent>().position.y = 200.0f;
		playerTwoEntity.addComponent<SpriteComponent>("assets/Baran.png");
		playerTwoEntity.addComponent<KeyboardControllerTwo>();
		playerTwoEntity.addComponent<Goat>(false);
	}
	else {
		AIEntity.addComponent<TransformComponent>();
		AIEntity.getComponent<TransformComponent>().position.x = 400.0f;
		AIEntity.getComponent<TransformComponent>().position.y = 200.0f;
		AIEntity.addComponent<SpriteComponent>("assets/Baran.png");
		AIEntity.addComponent<AIComponent>();
	}

	
}

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
	GameObjectInit();
}

void Game::handleEvents() {
	

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
bool booped = false;
void Game::update() {
	
	float x = playerEntity.getComponent<TransformComponent>().position.x;
	float y = playerEntity.getComponent<TransformComponent>().position.y;
	//
	//std::cout << playerEntity.getComponent<TransformComponent>().position.x << std::endl;
	playerEntity.getComponent<Goat>().circle_radius = circle_radius;
	
	manager.refresh();
	manager.update();
	cnt++;
	if (cnt == 6) {
		if (booped) booped = false;
		cnt = 0;
		circle_radius--;
	}
	if (circle_radius == 0) isRunning = false;
	if (multiplayer) {
		playerTwoEntity.getComponent<Goat>().circle_radius = circle_radius;
		if (Collision::getCollision(playerEntity.getComponent<TransformComponent>().position, playerTwoEntity.getComponent<TransformComponent>().position) && !booped) {
			playerTwoEntity.getComponent<TransformComponent>().velocity = tempCollisionHandler(playerTwoEntity.getComponent<TransformComponent>().velocity, playerEntity.getComponent<TransformComponent>().velocity);
			playerEntity.getComponent<TransformComponent>().velocity = tempCollisionHandler(playerTwoEntity.getComponent<TransformComponent>().velocity, playerEntity.getComponent<TransformComponent>().velocity);
			playerTwoEntity.getComponent<TransformComponent>().velocity.x = -playerTwoEntity.getComponent<TransformComponent>().velocity.x;
			playerTwoEntity.getComponent<TransformComponent>().velocity.y = -playerTwoEntity.getComponent<TransformComponent>().velocity.y;
			booped = true;
		}
	}
	else {
		AIEntity.getComponent<AIComponent>().SetTarget(x, y);
		if (Collision::getCollision(playerEntity.getComponent<TransformComponent>().position, AIEntity.getComponent<TransformComponent>().position) && !booped) {
			AIEntity.getComponent<TransformComponent>().velocity = tempCollisionHandler(AIEntity.getComponent<TransformComponent>().velocity, playerEntity.getComponent<TransformComponent>().velocity);
			playerEntity.getComponent<TransformComponent>().velocity = tempCollisionHandler(AIEntity.getComponent<TransformComponent>().velocity, playerEntity.getComponent<TransformComponent>().velocity);
			AIEntity.getComponent<TransformComponent>().velocity.x = -AIEntity.getComponent<TransformComponent>().velocity.x;
			AIEntity.getComponent<TransformComponent>().velocity.y = -AIEntity.getComponent<TransformComponent>().velocity.y;
			booped = true;
		}
	}
}

void Game::render() {
	/*SDL_RenderClear(renderer);
	stuff to render
	draw_circle(renderer, 400, 300, cnt, 0xFF, 0xFF, 0xFF, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderCopyEx(renderer, playerTex, NULL, &dstR, angle, NULL, SDL_FLIP_NONE);
	player->Render();
	for (int i = 0; i <= 3; i++) AI[i]->Render();
	draw_circle(renderer, 400, 300, 24, 0xFF, 0xFF, 0xFF, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderPresent(renderer);*/

	SDL_RenderClear(renderer);
	draw_circle(renderer, 400, 320, circle_radius, 0xFF, 0xFF, 0xFF, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}