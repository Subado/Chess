#ifndef GAME_HPP
#define GAME_HPP

#include <ResourceHolder.hpp>
#include <SFML/Graphics.hpp>
#include <BoardSquare.hpp>
#include <Piece.hpp>
#include <Pawn.hpp>
#include <iostream>
#include <cmath>
#include <array>

#define DEBUG

class Game
{
	std::array<std::array<BoardSquare, 8>, 8> m_boardOfSquares;
	TextureHolder m_textures;

	sf::Sprite m_boardSprite;
	sf::Sprite m_possibleMoveSprite;

	BoardSquare *m_selectedSquare;

	float m_lengthOfSquare;

public:
	Game();
	void handleMouseInput(const sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
};

#endif // GAME_HPP
