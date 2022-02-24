#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <World.hpp>

class App
{
public:
	App();
	void run();
	void handleEvents();
	void update(sf::Time elapsedTime);
	void render();

private:
	sf::RenderWindow m_window;
	World m_world;
};

#endif // APP_HPP
