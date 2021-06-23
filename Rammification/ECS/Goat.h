#pragma once
#include "../Game.h"
#include "Components.h"
#include <math.h>
#include <iostream>

class Goat : public Component {
public:
	bool player;
	Goat(bool player) {
		this->player = player;
	}

	TransformComponent* transform;
	int circle_radius;
	int points = 0;
	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		if (sqrtf(
			((transform->position.x - 400.0f + 32.0f) * (transform->position.x - 400.0f + 32.0f))
			+ ((transform->position.y - 320.0f + 32.0f) * (transform->position.y - 320.0f + 32.0f))
		)
			< circle_radius) 
		{
			points += 320/circle_radius;
		}
		//if (circle_radius <= 0) {
		//std::cout << transform->position.x - 400.0f + 32.0f << std::endl;
		if (player) std::cout << "player 1: ";
		else std::cout << "player 2: ";
		std::cout << points << std::endl;
		//}
	}
};