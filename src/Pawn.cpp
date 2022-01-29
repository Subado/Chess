#include <cassert>
#include <Pawn.hpp>

void Pawn::calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces)
{
	bool squareEmpty{true};

	unsigned int x{position.x}, y{position.y};

	if (direction.x)
	{
		x = position.y;
		y = position.x;
	}

	for (auto &i : pieces)
	{
		for (auto &j : i)
		{
			if ((sf::Vector2u(x - 1, y + direction.y) == j->getPosition()) ||
					(sf::Vector2u(x + 1, y + direction.y) == j->getPosition()))
			{
				possibleMoves.push_back(j->getPosition());
			}
			else if ((sf::Vector2u(position.x + direction.x, position.y + direction.y) == j->getPosition()))
			{
				squareEmpty = false;
			}
		}
	}

	if (squareEmpty)
	{
		possibleMoves.push_back((sf::Vector2u(position.x + direction.x, position.y + direction.y)));
	}

}

Pawn::Pawn(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team, const sf::Vector2i &direction, const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces)
	: Piece(texture, scale, position, k, team)
{
#ifdef DEBUG
	assert("Incorrect direction" && (direction.y || direction.x) && !(direction.y && direction.x) && direction.x >= -1 && direction.x <= 1 && direction.y >= -1 && direction.y <= 1);
#endif
	this->direction = direction;
	calculatePossibleMoves(pieces);
}

bool Pawn::move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &k)
{
	for (auto &i : possibleMoves)
	{
		if (position == i)
		{
			this->position = position;
			sprite.setPosition(position.x*k, position.y*k);
			possibleMoves.clear();
			calculatePossibleMoves(pieces);
			return true;
		}
	}

	return false;
}
