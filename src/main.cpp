#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <memory>
#include <Piece.hpp>
#include <Pawn.hpp>

#define DEBUG

int main()
{
    // create the window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Chess on C++");
	window.setFramerateLimit(60);

	std::array<char, 64> charBoard;

	sf::Texture boardTexture;
	sf::Texture possibleMoveTexture;
	std::array<sf::Texture, 6> textures;

	textures[0].loadFromFile("assets/images/black-pawn.png");
	possibleMoveTexture.loadFromFile("assets/images/transparent-circle.png");
	boardTexture.loadFromFile("assets/images/chess-board.png");

	sf::Sprite boardSprite;
	boardSprite.setTexture(boardTexture);
	boardSprite.scale(sf::Vector2f(static_cast<float>(700)/boardTexture.getSize().x, static_cast<float>(700)/boardTexture.getSize().y));

	sf::Sprite possibleMoveSprite;
	possibleMoveSprite.setTexture(possibleMoveTexture);
	possibleMoveSprite.setScale(boardSprite.getScale());

	const float k = boardSprite.getGlobalBounds().width/8;

	std::unique_ptr<Piece> *selectedPiece = nullptr;
	std::vector<std::vector<std::unique_ptr<Piece>>> pieces;
	pieces.push_back(std::vector<std::unique_ptr<Piece>>());
	pieces[0].push_back(std::make_unique<Pawn>(Pawn(&textures[0], boardSprite.getScale(), sf::Vector2u(6, 5), k, 0, sf::Vector2i(0, -1), pieces)));
	pieces[0].push_back(std::make_unique<Pawn>(Pawn(&textures[0], boardSprite.getScale(), sf::Vector2u(7, 6), k, 0, sf::Vector2i(0, -1), pieces)));

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
						if (selectedPiece)
						{
							(*selectedPiece)->move(pieces, sf::Vector2u(trunc(event.mouseButton.x / k), trunc(event.mouseButton.y / k)), k);
						}
						for (auto &i : pieces[0])
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
			for (auto &j : i)
			{
				window.draw(j->getSprite());
			}
		}
		if (selectedPiece)
		{

			for (auto &i : (*selectedPiece)->getPossibleMoves())
			{
				possibleMoveSprite.setPosition(k*i.x, k*i.y);
				window.draw(possibleMoveSprite);
			}
		}
		std::cout << "Bounds=" << boardSprite.getGlobalBounds().top << '\n';
		std::cout << "Pawn: x=" << pieces[0][0]->getSprite().getPosition().x << " y=" << pieces[0][0]->getSprite().getPosition().y << '\n';
		std::cout << "Window size: x=" << window.getSize().x << " y=" << window.getSize().y << '\n';
		std::cout << "selectedPiece=" << selectedPiece << '\n';

		// end the current frame
		window.display();
    }

	return 0;
}
