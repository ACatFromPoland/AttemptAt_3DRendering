#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "AdriansVector3s.h"


class Polygon {
public:
	std::vector<Vector3> pointList;
	sf::Color color;
	Polygon(Vector3 p1, Vector3 p2, Vector3 p3, sf::Color c) {
		pointList.push_back(p1);
		pointList.push_back(p2);
		pointList.push_back(p3);
		color = c;
	}

};