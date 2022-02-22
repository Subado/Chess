#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <ResourceHolder.hpp>
#include <SceneNode.hpp>
#include <vector>
#include <memory>

class Piece : public SceneNode
{
public:
	enum class Color
	{
		White,
		Black,
		Red,
		Blue,
		Green,
		Yellow
	};
	enum class Type
	{
		Pawn,
		Knight,
		Bishop,
		Rook,
		Queen,
		King
	};


	Piece(const TextureHolder &textures, uint8_t position, uint8_t team, Color color, Type type);

	uint8_t getPosition() const { return m_position; }
	uint8_t getTeam() const { return m_team; }

	virtual ~Piece() { }

protected:
	sf::Sprite m_sprite;
	uint8_t m_position;
	uint8_t m_team;

	virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // PIECE_HPP
