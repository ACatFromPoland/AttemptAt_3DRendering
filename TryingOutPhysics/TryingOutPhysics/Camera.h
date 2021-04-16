#pragma once
#include "Defines.h"
#include "AdriansVector3s.h"
#include "AdriansVector2s.h"
#include "Polygon.h"
#include "AdriansMatrix.h"
#include <SFML/Graphics.hpp>


class Camera {
public:
	Vector3 position = Vector3(10.f, 10.f, 0.f);
	Vector3 rotation = Vector3(0.f, 0.f, 0.f);
	sf::RenderWindow *rw;
	std::vector<std::vector<float>> projectionMatrix;

	std::vector<std::vector<float>> rotationX;
	std::vector<std::vector<float>> rotationY;
	std::vector<std::vector<float>> rotationZ;

	Camera(sf::RenderWindow &window) {
		rw = &window;

		projectionMatrix.push_back({ 1, 0, 0 });
		projectionMatrix.push_back({ 0, 1, 0 });

		rotationX.push_back({ 1.f, 0.f, 0.f });
		rotationX.push_back({ 0.f, cos(rotation.x) , -1 * sin(rotation.x) });
		rotationX.push_back({ 0.f, sin(rotation.x), cos(rotation.x) });

		rotationY.push_back({ cos(rotation.y), 0.f , sin(rotation.y) });
		rotationY.push_back({ 0.f,  1.f , 0.f });
		rotationY.push_back({ -1 * sin(rotation.y), 0.f, cos(rotation.y) });

		rotationZ.push_back({ cos(rotation.z), -1 * sin(rotation.z), 0.f });
		rotationZ.push_back({ sin(rotation.z), cos(rotation.z), 0.f });
		rotationZ.push_back({ 0.f, 0.f, 1.f });
	}
	
	void updateMatrix() {
		projectionMatrix[0] = { 1, 0, 0 };
		projectionMatrix[1] = { 0, 1, 0 };

		rotationX[0] = { 1.f, 0.f, 0.f };
		rotationX[1] = { 0.f, cos(rotation.x) , -1 * sin(rotation.x) };
		rotationX[2] = { 0.f, sin(rotation.x), cos(rotation.x) };

		rotationY[0] = { cos(rotation.y), 0.f , sin(rotation.y) };
		rotationY[1] = { 0.f,  1.f , 0.f };
		rotationY[2] = { -1 * sin(rotation.y), 0.f, cos(rotation.y) };

		rotationZ[0] = { cos(rotation.z), -1 * sin(rotation.z), 0.f };
		rotationZ[1] = { sin(rotation.z), cos(rotation.z), 0.f };
		rotationZ[2] = { 0.f, 0.f, 1.f };
	}
	
	Vector2 calculateProjection(Vector3 &polypoint) {
		updateMatrix();
		Vector3 rotatedPoint = polypoint;

		rotatedPoint = matrixMul(rotatedPoint, rotationX);
		rotatedPoint = matrixMul(rotatedPoint, rotationY);
		rotatedPoint = matrixMul(rotatedPoint, rotationZ);

		// Projecting to Screen
		Vector2 projectedPoint = matrixMulto2D(rotatedPoint, projectionMatrix);
		return projectedPoint;
	}
};