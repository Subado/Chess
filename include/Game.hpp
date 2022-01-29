#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <Piece.hpp>
#include <Pawn.hpp>
#include <iostream>
#include <cmath>
#include <array>

#define DEBUG

namespace
{
}

class Game
{
	std::array<char, 64> m_charBoard;
	std::array<sf::Texture, 6> m_textures;
	sf::Texture m_possibleMoveTexture;
	sf::Texture m_boardTexture;
	
	sf::Sprite m_boardSprite;
	sf::Sprite m_possibleMoveSprite;


	std::vector<std::vector<std::unique_ptr<Piece>>> m_pieces;
	std::unique_ptr<Piece> *m_selectedPiece;

	float m_lengthOfSquare;

public:
	Game();
	void handleEvents(const sf::Event &event);
	void draw(sf::RenderWindow &window);
};

#endif // GAME_HPP_
