#include <App.hpp>
#include <iostream>

App::App()
	: m_window(sf::VideoMode(700, 700), "Chess on C++"),
	m_scene(m_window)
{
	m_window.setFramerateLimit(60);
}

void App::run()
{
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.f/60);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window.isOpen())
    {
		for (timeSinceLastUpdate += clock.restart(); timeSinceLastUpdate > timePerFrame; timeSinceLastUpdate -= timePerFrame)
		{
			handleEvents();
			update(timePerFrame);
		}

		render();
	}
}

void App::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonPressed:
			default:
				break;
		}
	}
}

void App::update(sf::Time elapsedTime)
{
	m_scene.update(elapsedTime);
}

void App::render()
{
	m_window.clear();
	m_scene.draw(m_window);
	m_window.display();
}
