#pragma once
#include "ECS.h"
#include "../Vector2D.h"
#include "math.h"

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D size;

	float scale;

	float rotation = 0.0f;
	TransformComponent(float x = 0.0f, float y = 0.0f) {
		setPos(x, y);
	}
	void init() override {
		setPos(0.0f, 0.0f);
		setVelocitiy(0.0f, 0.0f);
		setAcceleration(0.0f, 0.0f);
		setSize(64.0f, 64.0f);
	}

	void update() override {
		velocity.x += acceleration.x / 60;
		velocity.y += acceleration.y / 60;
		position.x += velocity.x / 60;
		position.y += velocity.y / 60;
		velocity.x -= velocity.x * 0.06f;
		velocity.y -= velocity.y * 0.06f;
		updateAngle();
	}

	void updateAngle() {
		float angle = atan2(-velocity.x, velocity.y);
		float degrees = 180 * angle / M_PI;
		rotation = degrees;
	}

	void setPos(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void setVelocitiy(float x, float y) {
		velocity.x = x;
		velocity.y = y;
	}
	void setAcceleration(float x, float y) {
		acceleration.x = x;
		acceleration.y = y;
	}
	void setSize(float x, float y) {
		size.x = x;
		size.y = y;
	}
};