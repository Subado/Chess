#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#pragma once

class Piece
{
protected:
	sf::Texture *const texture;
	sf::Sprite sprite;
	sf::Vector2u position;
	uint8_t team;
	std::vector<sf::Vector2u> possibleMoves;

	virtual void calculatePossibleMoves(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces) = 0;
public:
	Piece(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team);

	const sf::Sprite &getSprite() const { return sprite; }
	const sf::Vector2u &getPosition() const { return position; }
	uint8_t getTeam() const { return team; }
	std::vector<sf::Vector2u> getPossibleMoves() { return possibleMoves; };

	virtual bool move(const std::vector<std::vector<std::unique_ptr<Piece>>> &pieces, const sf::Vector2u &position, const float &k) = 0;

	virtual ~Piece() {}
};
