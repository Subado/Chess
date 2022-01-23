#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include "Piece.h"
#include "Pawn.h"

int main()
{
    // create the window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Chess on C++");
	window.setFramerateLimit(60);

	sf::Texture boardTexture;
	sf::Texture possibleMoveTexture;
	std::array<sf::Texture, 6> textures;

	textures[0].loadFromFile("resources/black-pawn.png");
	possibleMoveTexture.loadFromFile("resources/transparent-circle.png");
	boardTexture.loadFromFile("resources/chess-board.png");

	sf::Sprite boardSprite;
	boardSprite.setTexture(boardTexture);
	boardSprite.scale(sf::Vector2f(static_cast<float>(700)/boardTexture.getSize().x, static_cast<float>(700)/boardTexture.getSize().y));

	sf::Sprite possibleMove;
	possibleMove.setTexture(possibleMoveTexture);
	possibleMove.setScale(boardSprite.getScale());

	const float k = boardSprite.getGlobalBounds().width/8;

	std::unique_ptr<Piece> *selectedPiece = nullptr;
	std::vector<std::unique_ptr<Piece>> pieces;
	pieces.push_back(std::make_unique<Pawn>(Pawn(&textures[0], boardSprite.getScale(), sf::Vector2u(7, 6), k, sf::Vector2i(1, 1), 0, pieces)));
	pieces.push_back(std::make_unique<Pawn>(Pawn(&textures[0], boardSprite.getScale(), sf::Vector2u(6, 5), k, sf::Vector2i(1, 1), 0, pieces)));

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
			case sf::Event::MouseButtonPressed:
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						for (auto &i : pieces)
						{
							if ((event.mouseButton.x >= i->getSprite().getPosition().x && event.mouseButton.x <= i->getSprite().getPosition().x + i->getSprite().getGlobalBounds().width) &&
									(event.mouseButton.y >= i->getSprite().getPosition().y && event.mouseButton.y <= i->getSprite().getPosition().y + i->getSprite().getGlobalBounds().height))
							{
								selectedPiece = &i;
							}
						}
					}
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
		for (auto &i : pieces)
		{
			window.draw(i->getSprite());
		}
		if (selectedPiece)
		{

			for (auto &i : (*selectedPiece)->getPossibleMoves())
			{
				possibleMove.setPosition(k*i.x, k*i.y);
				window.draw(possibleMove);
			}
		}
		std::cout << "Bounds=" << boardSprite.getGlobalBounds().top << '\n';
		std::cout << "Pawn: x=" << pieces[0]->getSprite().getPosition().x << " y=" << pieces[0]->getSprite().getPosition().y << '\n';
		std::cout << "Window size: x=" << window.getSize().x << " y=" << window.getSize().y << '\n';
		std::cout << "selectedPiece=" << selectedPiece << '\n';

		// end the current frame
		window.display();
    }

	return 0;
}
