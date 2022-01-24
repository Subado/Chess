#include "Piece.h"

Piece::Piece(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team)
	: position(position), team(team), texture(texture)
{
	sprite.setTexture(*this->texture);
	sprite.setScale(scale);
	sprite.setPosition(position.x*k, position.y*k);
}
