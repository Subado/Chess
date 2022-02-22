#ifndef PAWN_HPP
#define PAWN_HPP

#include <Piece.hpp>

class Pawn : public Piece
{
public:
	Pawn(const TextureHolder &textures, uint8_t position, uint8_t team, Color color, int direction);

protected:
	int m_direction;
};

#endif // PAWN_HPP
