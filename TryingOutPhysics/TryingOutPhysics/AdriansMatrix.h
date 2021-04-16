#pragma once
#include "AdriansVector3s.h"
#include "AdriansVector2s.h"
#include "Defines.h"

Vector2 matrixMulto2D(Vector3 &polypoint, std::vector<std::vector<float>> &projection) {
	Vector2 outputVector = Vector2(0.f, 0.f);
	outputVector.x = (projection[0][0] * polypoint.x) + (projection[0][1] * polypoint.y) + (projection[0][2] * polypoint.z);
	outputVector.y = (projection[1][0] * polypoint.x) + (projection[1][1] * polypoint.y) + (projection[1][2] * polypoint.z);
	return outputVector;
}

Vector3 matrixMul(Vector3 &polypoint, std::vector<std::vector<float>> &matrix) {
	Vector3 outputVector = Vector3(0.f, 0.f, 0.f);
	outputVector.x = (matrix[0][0] * polypoint.x) + (matrix[0][1] * polypoint.y) + (matrix[0][2] * polypoint.z);
	outputVector.y = (matrix[1][0] * polypoint.x) + (matrix[1][1] * polypoint.y) + (matrix[1][2] * polypoint.z);
	outputVector.z = (matrix[2][0] * polypoint.x) + (matrix[2][1] * polypoint.y) + (matrix[2][2] * polypoint.z);
	return outputVector;
}