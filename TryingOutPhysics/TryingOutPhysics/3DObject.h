#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "AdriansVector3s.h"
#include "Camera.h"
#include "Polygon.h"

class Object3D {
public:
	std::vector<Polygon> mesh;
	
	Object3D() {
		// Side Front
		Polygon polygon = Polygon(Vector3(0.f, 100.f, 0.f), Vector3(100.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f), sf::Color(255, 0, 0));
		mesh.push_back(polygon);

		polygon = Polygon(Vector3(0.f, 100.f, 0.f), Vector3(100.f, 0.f, 0.f), Vector3(100.f, 100.f, 0.f), sf::Color(125, 0, 0));
		mesh.push_back(polygon);

		// Side Back
		polygon = Polygon(Vector3(0.f, 100.f, 100.f), Vector3(100.f, 0.f, 100.f), Vector3(0.f, 0.f, 100.f), sf::Color(0, 0, 255));
		mesh.push_back(polygon);

		polygon = Polygon(Vector3(0.f, 100.f, 100.f), Vector3(100.f, 0.f, 100.f), Vector3(100.f, 100.f, 100.f), sf::Color(0, 0, 125));
		mesh.push_back(polygon);

		// Side Top
		polygon = Polygon(Vector3(0.f, 100.f, 0.f), Vector3(100.f, 100.f, 0.f), Vector3(0.f, 100.f, 100.f), sf::Color(0, 255, 0));
		mesh.push_back(polygon);

		polygon = Polygon(Vector3(100.f, 100.f, 0.f), Vector3(100.f, 100.f, 100.f), Vector3(0.f, 100.f, 100.f), sf::Color(0, 125, 0));
		mesh.push_back(polygon);

		// Side Bottom
		polygon = Polygon(Vector3(0.f, 0.f, 0.f), Vector3(100.f, 0.f, 0.f), Vector3(0.f, 0.f, 100.f), sf::Color(255, 255, 0));
		mesh.push_back(polygon);

		polygon = Polygon(Vector3(100.f, 0.f, 0.f), Vector3(100.f, 0.f, 100.f), Vector3(0.f, 0.f, 100.f), sf::Color(125, 125, 0));
		mesh.push_back(polygon);
	}

	void draw(sf::RenderWindow &window, Camera &c) {
		for (int i = 0; i < mesh.size(); i++) {  // For each polygon
			Polygon &poly = mesh[i];
			sf::ConvexShape poly2d; // Create a drawable 2d polygon
			poly2d.setPointCount(3); // Set it to have 3 points aka a triangle
			for (int i = 0; i < poly.pointList.size(); i++) { // For each point on the polygon
				Vector2 projPoint = c.calculateProjection(poly.pointList[i]); // Calculate the projection
				poly2d.setPoint(i, projPoint.asSF()); // Apply the position to the 2d drawable polygon
			} 
			poly2d.setPosition(WINDOWX / 2, WINDOWY / 2);
			poly2d.setFillColor(poly.color);
			window.draw(poly2d); // Draw the 2d drawable polygon
		}
	}
};