#include <App.hpp>

App::App() : m_window(sf::VideoMode(700, 700), "Chess on C++")
{
	m_window.setFramerateLimit(60);
}

void App::run()
{
	Game game;
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::Resized:
                {
                    sf::FloatRect view(0, 0, event.size.width, event.size.height);
                    m_window.setView(sf::View(view));
                    break;
                }
				case sf::Event::MouseButtonPressed:
					game.handleMouseInput(m_window);
                default:
                    break;
            }
        }
        m_window.clear();
		game.draw(m_window);
        m_window.display();
	}
}
