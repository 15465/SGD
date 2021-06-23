#pragma once
#include "../Game.h"
#include "SDL.h"
#include "Components.h"
#include "../Collison.h"

class AIComponent : public Component {
public:
	TransformComponent* transform;
	Vector2D playerPosition;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {
		MoveTowards(playerPosition);
	}
	void MoveTowards(Vector2D point) {
		transform->acceleration.x = point.x - transform->position.x;
		transform->acceleration.y = point.y - transform->position.y;

		//normalizacja wektora
		float magnitude = sqrt((transform->acceleration.x * transform->acceleration.x) + (transform->acceleration.y * transform->acceleration.y));
		transform->acceleration.x = transform->acceleration.x * 5000.0f / magnitude;
		transform->acceleration.y = transform->acceleration.y * 5000.0f / magnitude;
	}
	void SetTarget(float x, float y) {
		playerPosition.x = x;
		playerPosition.y = y;
	}

};