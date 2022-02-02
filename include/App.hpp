#ifndef APP_HPP
#define APP_HPP
#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <iostream>
#include <array>
class App
{
	sf::RenderWindow m_window;
public:
	App();
	void run();
};

#endif // APP_HPP
