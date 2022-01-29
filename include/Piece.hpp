#ifndef PIECE_HPP_
#define PIECE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Piece
{
protected:
	sf::Texture *const m_texture;
	sf::Sprite m_sprite;
	sf::Vector2u m_position;
	uint8_t m_teamNum;
	std::vector<sf::Vector2u> m_possibleMoves;

	virtual void calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) = 0;
public:
	Piece(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team);

	const sf::Sprite &getSprite() const { return m_sprite; }
	const sf::Vector2u &getPosition() const { return m_position; }
	uint8_t getTeam() const { return m_teamNum; }
	std::vector<sf::Vector2u> getPossibleMoves() { return m_possibleMoves; };

	virtual bool move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &k) = 0;

	virtual ~Piece() {}
};

#endif // PIECE_HPP_
