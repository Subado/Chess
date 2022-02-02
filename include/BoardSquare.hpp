#ifndef BOARD_SQUARE_HPP
#define BOARD_SQUARE_HPP

#include <memory>

class Piece;

class BoardSquare
{
	std::shared_ptr<Piece> m_piece;
public:
	BoardSquare();
	BoardSquare(std::shared_ptr<Piece> piece);

	bool isNotEmpty() const;
	bool isEmpty() const;

	Piece &operator * ();
	const Piece &operator * () const;
	const BoardSquare &operator = (std::shared_ptr<Piece> piece);

	void movePiece(BoardSquare &boardSquare);
};

#endif // BOARD_SQUARE_HPP
