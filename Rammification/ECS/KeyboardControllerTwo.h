#pragma once

#include "../Game.h"
#include "Components.h"
#include <math.h>
class KeyboardControllerTwo : public Component {
public:
	TransformComponent* transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_i:
				transform->acceleration.y = -5000.0f;
				break;
			case SDLK_k:
				transform->acceleration.y = 5000.0f;
				break;
			case SDLK_j:
				transform->acceleration.x = -5000.0f;
				break;
			case SDLK_l:
				transform->acceleration.x = 5000.0f;
				break;
			default:
				break;
			}
		}
		if (Game::event.type == SDL_KEYUP) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_i:
				transform->acceleration.y = 0.0f;
				break;
			case SDLK_k:
				transform->acceleration.y = 0.0f;
				break;
			case SDLK_j:
				transform->acceleration.x = 0.0f;
				break;
			case SDLK_l:
				transform->acceleration.x = 0.0f;
			default:
				break;
			}
		}
	}
};