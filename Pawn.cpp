#include "Pawn.h"

void Pawn::calculatePossibleMoves(const std::vector<std::unique_ptr<Piece>> &pieces)
{
	bool squareEmpty{true};

	for (auto &i : pieces)
	{
		if ((sf::Vector2u(position.x - 1, position.y - 1) == i->getPosition()) ||
				(sf::Vector2u(position.x + 1, position.y - 1) == i->getPosition()))
		{
			possibleMoves.push_back(i->getPosition());
		}
		else if ((sf::Vector2u(position.x, position.y - 1) == i->getPosition()))
		{
			squareEmpty = false;
		}
	}

	if (squareEmpty)
	{
		possibleMoves.push_back((sf::Vector2u(position.x, position.y - 1)));
	}

}

Pawn::Pawn(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, const sf::Vector2i &direction, uint8_t team, const std::vector<std::unique_ptr<Piece>> &pieces)
	: Piece(texture, scale, position, k, direction, team)
{
	calculatePossibleMoves(pieces);
}

void Pawn::move(const std::vector<std::unique_ptr<Piece>> &pieces, const sf::Vector2u &position, const float &k)
{
	for (auto &i : possibleMoves)
	{
		if (position == i)
		{
			this->position = position;
			sprite.setPosition(position.x*k, position.y*k);
			break;
		}
	}
}
