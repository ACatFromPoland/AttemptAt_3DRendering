#pragma once
#include <SFML/Graphics.hpp>

class Vector3 {
public:
	float x;
	float y;
	float z;

	Vector3(float xa, float ya, float za) { x = xa; y = ya; z = za; }

	Vector3 operator+(const Vector3& given) const { return Vector3(x + given.x, y + given.y, z + given.z); }
	Vector3 operator-(const Vector3& given) const { return Vector3(x - given.x, y - given.y, z - given.z); }
	Vector3 operator*(const float& given) const { return Vector3(x * given, y * given, z * given); }
	Vector3 operator/(const float& given) const { return Vector3(x / given, y / given, z * given); }

	double distanceTo(Vector3 v3) {
		return sqrt(
			(v3.x - x) * (v3.x - x) + 
			(v3.y - y) * (v3.y - y) + 
			(v3.z - z) * (v3.z - z)
		);
	}

	void normalized() {
		float iradius = 1.f / (sqrtf(x*x + y*y + z*z));
		x *= iradius; y *= iradius; z *= iradius;
	}
	
	void setCord(float xa, float ya, float za) {
		x = xa; y = ya; z = za;
	}
};