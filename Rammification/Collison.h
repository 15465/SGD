#pragma once
#include <SDL.h>
#include <math.h>
#include "Vector2D.h"
class Collision {
public:
	static bool getCollision(Vector2D c1, Vector2D c2) {
		if (sqrt(((c1.x - c2.x) * (c1.x - c2.x)) + ((c1.y - c2.y) * (c1.y - c2.y))) <= 64.0f) {
			return true;
		}
		return false;
	}
};