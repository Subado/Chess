#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <Scene.hpp>

class App
{
	sf::RenderWindow m_window;
	Scene m_scene;
public:
	App();
	void run();
	void handleEvents();
	void update(sf::Time elapsedTime);
	void render();
};

#endif // APP_HPP
