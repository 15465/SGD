#pragma once
#include <iostream>

class Vector2D {
public:
	float x;
	float y;

	Vector2D(float x = 0.0f, float y = 0.0f);

	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& v2);
	Vector2D& operator-=( const Vector2D& v2);
	Vector2D& operator*=(const Vector2D& v2);
	Vector2D& operator/=(const Vector2D& v2);

	friend std::ostream& operator << (std::ostream& stream, const Vector2D& v);
};