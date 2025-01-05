#include <iostream>

#include <SFML/Graphics.hpp>

struct WindowHandler {
public: 
	WindowHandler() {
		std::cout << "WindowHandler constructor" << std::endl;
	}
	~WindowHandler() {
		std::cout << "WindowHandler destructor" << std::endl;
	}
};