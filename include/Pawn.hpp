#ifndef PAWN_HPP
#define PAWN_HPP

#include <Piece.hpp>

class Pawn : public Piece
{
	sf::Vector2i m_direction;

	void calculatePossibleMoves(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares) override;
public:
	Pawn(const sf::Texture &texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &lengthOfSquare, uint8_t team, const sf::Vector2i &direction, const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares);

	void move(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares, const sf::Vector2u &position, const float &lengthOfSquare) override;
};

#endif // PAWN_HPP
