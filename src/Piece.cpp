#include <Piece.hpp>

Piece::Piece(const sf::Texture &texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &lengthOfSquare, uint8_t team)
	: m_position(position), m_teamNum(team)
{
	m_sprite.setTexture(texture);
	m_sprite.setScale(scale);
	m_sprite.setPosition(position.x*lengthOfSquare, position.y*lengthOfSquare);
}
