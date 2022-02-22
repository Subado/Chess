#include <Pawn.hpp>
#include <cassert>

Pawn::Pawn(const TextureHolder &textures, uint8_t position, uint8_t team, Color color, int direction)
	: Piece(textures, position, team, color, Piece::Type::Pawn)
{
	m_direction = direction;
}
