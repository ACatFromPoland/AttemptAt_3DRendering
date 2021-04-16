#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "3DObject.h"

class MousePointer {
public:
	Vector2 position = Vector2(0.f, 0.f);
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Rendering3D", sf::Style::Close);
	sf::Clock clock;
	Camera camera(window);
	Object3D cube;

	Vector2 mouseorigin = Vector2(0.f, 0.f);
	bool letgo = true;

	sf::Vector2i ms = sf::Mouse::getPosition();
	sf::Vector2i mn = sf::Mouse::getPosition();

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float deltatime = clock.restart().asSeconds();
		window.clear(sf::Color::Black);
		//

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (letgo) {
				ms = sf::Mouse::getPosition();
				mouseorigin.x = ms.x;
				mouseorigin.y = ms.y;
				letgo = false;
			}
			else {
				mn = sf::Mouse::getPosition();
				//camera.rotation = Vector3(-1 * (mn.x - ms.x), -1 * (mn.y - ms.y), 0.f) * 0.01;
				camera.rotation = Vector3(-1* (mn.y - ms.y), (mn.x - ms.x), 0.f) * 0.01;
			}
		}
		else {
			letgo = true;
		}

		//
		cube.draw(window, camera);
		window.display();

	}
	return 0;
}

/*
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
camera.rotation = camera.rotation + Vector3(2.f, 0.f, 0.f) * deltatime; // X
}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
//	camera.rotation = camera.rotation + Vector3(0.f, 1.f, 0.f) * deltatime;
//}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
camera.rotation = camera.rotation + Vector3(0.f, 2.f, 0.f) * deltatime; // Y
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
camera.rotation = camera.rotation + Vector3(0.f, 0.f, 2.f) * deltatime; // Z
}
*/