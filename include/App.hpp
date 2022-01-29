#ifndef APP_HPP_
#define APP_HPP_
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

#endif // APP_HPP_
