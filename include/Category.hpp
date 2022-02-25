#ifndef CATEGORY_HPP
#define CATEGORY_HPP

namespace Category
{
	enum class Type
	{
		None = 0,
		Scene = 1 << 0,
		PlayerPiece = 1 << 1,
		ComputerPiece = 1 << 2,
		SelectedPiece = 1 << 3
	};
}

#endif // CATEGORY_HPP
