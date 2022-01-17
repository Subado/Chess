#include "Piece.h"

Piece::Piece(const sf::Vector2f &scale, const std::string &img, const sf::Vector2f &position, const double &k)
{
	texture.loadFromFile(img);
	sprite.setTexture(texture);
	sprite.setScale(scale);
	sprite.setPosition(position.x*k, position.y*k);
}

void Piece::move(const sf::Vector2f &position, const double &k)
{
	sprite.setPosition(position.x*k, position.y*k);
}
