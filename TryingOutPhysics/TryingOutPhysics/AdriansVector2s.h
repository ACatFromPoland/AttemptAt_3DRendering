#pragma once
#include <SFML/Graphics.hpp>
#include "AdriansVector3s.h"

class Vector2 {
public:
	float x;
	float y;

	Vector2(float xa, float ya) {
		x = xa;
		y = ya;
	}

	Vector2 operator+(const Vector2& given) const {
		return Vector2(x + given.x, y + given.y);
	}
	Vector2 operator-(const Vector2& given) const {
		return Vector2(x - given.x, y - given.y);
	}
	Vector2 operator*(const float& given) const {
		return Vector2(x * given, y * given);
	}
	Vector2 operator/(const float& given) const {
		return Vector2(x / given, y / given);
	}

	double distanceTo(Vector2 v2) {
		return sqrt(((v2.x - x) * (v2.x - x)) + ((v2.y - y) * (v2.y - y)));
	}
	void normalized() {
		float iradius = 1.f / (sqrtf(x*x + y*y));
		x *= iradius;
		y *= iradius;
	}
	sf::Vector2f asSF() const {
		return *(sf::Vector2f*)this;
	}
	Vector3 asVector3() {
		return Vector3(this->x, this->y, 0.f);
	}

	void setCord(float xa, float ya) {
		x = xa;
		y = ya;
	}

};
Vector2 asVector2(const sf::Vector2f& given) {
	return Vector2(given.x, given.y);
}