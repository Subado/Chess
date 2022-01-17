#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1920), "My window");
	sf::Texture boardTexture;

	if (!boardTexture.loadFromFile("chess-board.png"))
	{
		throw "bad textures";
	}

	sf::Sprite boardSprite;
	boardSprite.setTexture(boardTexture);
	boardSprite.scale(sf::Vector2f(float(700)/boardTexture.getSize().x, float(700)/boardTexture.getSize().y));
	Piece blackPawn(boardSprite.getScale(), "black-pawn.png", sf::Vector2f(3.0, 3.0), boardSprite.getGlobalBounds().width/8);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
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

        // clear the window with black color
        window.clear();

        // draw everything here...
        window.draw(boardSprite);
		window.draw(blackPawn.sprite);
		std::cout << "Bounds=" << boardSprite.getGlobalBounds().top << '\n';
		std::cout << "Pawn: x=" << blackPawn.sprite.getPosition().x << " y=" << blackPawn.sprite.getPosition().y << '\n';
		std::cout << "Window size: x=" << window.getSize().x << " y=" << window.getSize().y << '\n';

        // end the current frame
        window.display();
    }

	return 0;
}
