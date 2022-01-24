#include "Piece.h"

#pragma once

class Pawn : public Piece
{
	sf::Vector2i direction;

	void calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) override;
public:
	Pawn(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team, const sf::Vector2i &direction, const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces);

	bool move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &k) override;
};
