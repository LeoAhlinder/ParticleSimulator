#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "./engine/window_handler.hpp"

int main() {
	const uint32_t windowWidth = 1280;
	const uint32_t windowHeight = 720;

	sf::RenderWindow window(sf::VideoMode({800, 600}), "Simulator");
	window.setActive(true);

	WindowHandler windowHandler(window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}