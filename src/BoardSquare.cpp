#include <BoardSquare.hpp>

BoardSquare::BoardSquare() : m_piece(nullptr)
{
}

BoardSquare::BoardSquare(std::shared_ptr<Piece> piece) : m_piece(piece)
{
}

bool BoardSquare::isNotEmpty() const
{
	if (m_piece)
	{
		return true;
	}

	return false;
}

bool BoardSquare::isEmpty() const
{
	if (m_piece)
	{
		return false;
	}

	return true;
}

Piece &BoardSquare::operator * ()
{
#ifdef DEBUG
	assert("No one is standing on this BoardSquare" && isNotEmpty());
#endif
	return *m_piece;
}

const Piece &BoardSquare::operator * () const
{
#ifdef DEBUG
	assert("No one is standing on this BoardSquare" && isNotEmpty());
#endif
	return *m_piece;
}

const BoardSquare &BoardSquare::operator = (std::shared_ptr<Piece> piece)
{
#ifdef DEBUG
	assert("On this BoardSquare already stay piece" && isNotEmpty());
#endif
	m_piece = piece;

	return *this;
}

void movePiece(BoardSquare &boardSquare)
{
#ifdef DEBUG
	assert("No one is standing on this BoardSquare" && isNotEmpty());
#endif
}
