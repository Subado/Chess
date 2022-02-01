#ifndef GAME_HPP_
#define GAME_HPP_

#include <ResourceHolder.hpp>
#include <SFML/Graphics.hpp>
#include <Piece.hpp>
#include <Pawn.hpp>
#include <iostream>
#include <cmath>
#include <array>

#define DEBUG

class Game
{
	std::vector<std::vector<char>> m_charBoard;
	TextureHolder m_textures;

	sf::Sprite m_boardSprite;
	sf::Sprite m_possibleMoveSprite;

	std::vector<std::vector<std::unique_ptr<Piece>>> m_pieces;
	std::unique_ptr<Piece> *m_selectedPiece;

	float m_lengthOfSquare;

public:
	Game();
	void handleMouseInput(const sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
};

#endif // GAME_HPP_
