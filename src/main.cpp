#include <SFML/Graphics.hpp>
#include <iostream>
#include <App.hpp>

#define DEBUG

int main()
{
    // create the window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Chess on C++");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
        {
			switch (event.type)
			{
			case sf::Event::Closed:
                window.close();
				break;
			case sf::Event::Resized:
				{
					sf::FloatRect view(0, 0, event.size.width, event.size.height);
					window.setView(sf::View(view));
					break;
				}
			default:
				break;
			}
		}

		// game.handleEvents();
		window.clear();
		// game.draw(window);	
		window.display();

   /*      std::cout << "Bounds=" << boardSprite.getGlobalBounds().top << '\n'; */
		/* std::cout << "Pawn: x=" << pieces[0][0]->getSprite().getPosition().x << " y=" << pieces[0][0]->getSprite().getPosition().y << '\n'; */
		/* std::cout << "Window size: x=" << window.getSize().x << " y=" << window.getSize().y << '\n'; */
		/* std::cout << "selectedPiece=" << selectedPiece << '\n'; */

		// end the current frame
    }

	return 0;
}
