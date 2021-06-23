#pragma once
#include "../Game.h"
#include "SDL.h"
#include "Components.h"
#include "../Collison.h"

class ColldierComponent : Component {
public:
	TransformComponent* transform;

	void init() override {
		transform = &entity->getComponent<TransformComponent>();
	}
};