#include "Piece.h"

#pragma once

class Pawn : public Piece
{
	void calculatePossibleMoves(const std::vector<std::unique_ptr<Piece>> &pieces) override;
public:
	Pawn(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, const sf::Vector2i &direction, uint8_t team, const std::vector<std::unique_ptr<Piece>> &pieces);

	void move(const std::vector<std::unique_ptr<Piece>> &pieces, const sf::Vector2u &position, const float &k) override;
};
