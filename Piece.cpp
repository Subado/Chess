#include "Piece.h"

Piece::Piece(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, const sf::Vector2i &direction, uint8_t team)
	: position(position), direction(direction), team(team), texture(texture)
{
	sprite.setTexture(*this->texture);
	sprite.setScale(scale);
	sprite.setPosition(position.x*k, position.y*k);
}
