#include <cassert>
#include <Pawn.hpp>

void Pawn::calculatePossibleMoves(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares)
{
	int xOffset{m_direction.x}, yOffset{m_direction.y};

	if (m_direction.x)
	{
		xOffset = m_position.y;
		yOffset = m_position.x;
	}
	if (m_position.x + xOffset < 0 || m_position.x + xOffset > boardOfSquares.size() ||
			m_position.y + yOffset < 0 || m_position.y + yOffset > boardOfSquares[0].size())
	{
		return;
	}
	else
	{
		if (boardOfSquares[m_position.x - 1][m_position.y + yOffset].isNotEmpty()
				&& (*boardOfSquares[m_position.x - 1][m_position.y + yOffset]).getTeam() != m_teamNum)
		{
			m_possibleMoves.push_back(sf::Vector2u(m_position.x - 1, m_position.y + yOffset));
		}
		if (boardOfSquares[m_position.x + 1][m_position.y + yOffset].isNotEmpty()
				&& (*boardOfSquares[m_position.x + 1][m_position.y + yOffset]).getTeam() != m_teamNum)
		{
			m_possibleMoves.push_back(sf::Vector2u(m_position.x + 1, m_position.y + yOffset));
		}
		if (boardOfSquares[m_position.x][m_position.y + yOffset].isEmpty())
		{
			m_possibleMoves.push_back(sf::Vector2u(m_position.x, m_position.y + yOffset));
		}
	}
}

Pawn::Pawn(const sf::Texture &texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &lengthOfSquare, uint8_t team, const sf::Vector2i &direction, const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares)
	: Piece(texture, scale, position, lengthOfSquare, team)
{
#ifdef DEBUG
	assert("Incorrect direction" && (direction.y || direction.x) && !(direction.y && direction.x) && direction.x >= -1 && direction.x <= 1 && direction.y >= -1 && direction.y <= 1);
#endif
	this->m_direction = direction;
	calculatePossibleMoves(boardOfSquares);
}

void Pawn::move(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares, const sf::Vector2u &position, const float &lengthOfSquare)
{
	for (auto &i : m_possibleMoves)
	{
		if (position == i)
		{
			this->m_position = position;
			m_sprite.setPosition(position.x*lengthOfSquare, position.y*lengthOfSquare);
			m_possibleMoves.clear();
			calculatePossibleMoves(boardOfSquares);
		}
	}
}
