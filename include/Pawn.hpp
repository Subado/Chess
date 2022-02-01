#ifndef PAWN_HPP_
#define PAWN_HPP_

#include <Piece.hpp>

class Pawn : public Piece
{
	sf::Vector2i m_direction;

	void calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) override;
public:
	Pawn(const sf::Texture &texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &lengthOfSquare, uint8_t team, const sf::Vector2i &direction, const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces);

	bool move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &lengthOfSquare) override;
};

#endif // PAWN_HPP_
