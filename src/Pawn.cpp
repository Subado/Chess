#include <cassert>
#include <Pawn.hpp>

void Pawn::calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces)
{
	bool squareEmpty{true};

	unsigned int x{m_position.x}, y{m_position.y};

	if (m_direction.x)
	{
		x = m_position.y;
		y = m_position.x;
	}

	for (auto &i : pieces)
	{
		for (auto &j : i)
		{
			if ((sf::Vector2u(x - 1, y + m_direction.y) == j->getPosition()) ||
					(sf::Vector2u(x + 1, y + m_direction.y) == j->getPosition()))
			{
				m_possibleMoves.push_back(j->getPosition());
			}
			else if ((sf::Vector2u(m_position.x + m_direction.x, m_position.y + m_direction.y) == j->getPosition()))
			{
				squareEmpty = false;
			}
		}
	}

	if (squareEmpty)
	{
		m_possibleMoves.push_back((sf::Vector2u(m_position.x + m_direction.x, m_position.y + m_direction.y)));
	}

}

Pawn::Pawn(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team, const sf::Vector2i &direction, const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces)
	: Piece(texture, scale, position, k, team)
{
#ifdef DEBUG
	assert("Incorrect direction" && (direction.y || direction.x) && !(direction.y && direction.x) && direction.x >= -1 && direction.x <= 1 && direction.y >= -1 && direction.y <= 1);
#endif
	this->m_direction = direction;
	calculatePossibleMoves(pieces);
}

bool Pawn::move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &k)
{
	for (auto &i : m_possibleMoves)
	{
		if (position == i)
		{
			this->m_position = position;
			m_sprite.setPosition(position.x*k, position.y*k);
			m_possibleMoves.clear();
			calculatePossibleMoves(pieces);
			return true;
		}
	}

	return false;
}
