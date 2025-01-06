#include <SFML/Graphics.hpp>

class EventMananger {
public:
	EventMananger(sf::RenderWindow& window): m_win {
		m_window(window) 
	{}



private:
	sf::RenderWindow& m_window;
};