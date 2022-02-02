#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>
#include <BoardSquare.hpp>
#include <vector>
#include <memory>

class Piece
{
protected:
	sf::Sprite m_sprite;
	sf::Vector2u m_position;
	uint8_t m_teamNum;
	std::vector<sf::Vector2u> m_possibleMoves;

	virtual void calculatePossibleMoves(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares) = 0;
public:
	Piece(const sf::Texture &texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &lengthOfSquare, uint8_t team);

	const sf::Sprite &getSprite() const { return m_sprite; }
	const sf::Vector2u &getPosition() const { return m_position; }
	uint8_t getTeam() const { return m_teamNum; }
	const std::vector<sf::Vector2u> &getPossibleMoves() const { return m_possibleMoves; };

	virtual void move(const std::array<std::array<BoardSquare, 8>, 8> &boardOfSquares, const sf::Vector2u &position, const float &lengthOfSquare) = 0;

	virtual ~Piece() {}
};

#endif // PIECE_HPP
