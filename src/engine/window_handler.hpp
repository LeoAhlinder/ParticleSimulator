#include <iostream>

#include <SFML/Graphics.hpp>

struct WindowHandler {
public: 
	WindowHandler(sf::RenderWindow& window) {
		registerCallBacks(window);
	}
	~WindowHandler() {
		std::cout << "WindowHandler destructor" << std::endl;
	}


	void registerCallBacks(sf::RenderWindow& window) {
		window.setActive(true);
	}
};