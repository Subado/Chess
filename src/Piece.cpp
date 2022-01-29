#include <Piece.hpp>

Piece::Piece(sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2u &position, const float &k, uint8_t team)
	: m_position(position), m_teamNum(team), m_texture(texture)
{
	m_sprite.setTexture(*this->m_texture);
	m_sprite.setScale(scale);
	m_sprite.setPosition(position.x*k, position.y*k);
}
