#ifndef RESOURCE_IDENTIFIERS_HPP
#define RESOURCE_IDENTIFIERS_HPP

namespace sf
{
	class Texture;
	class Font;
}

namespace Textures
{
	enum class ID
	{
		WhitePawn,
		WhiteKnight,
		WhiteBishop,
		WhiteRook,
		WhiteQueen,
		WhiteKing,

		BlackPawn,
		BlackKnight,
		BlackBishop,
		BlackRook,
		BlackQueen,
		BlackKing,

		Board,
		PossibleMove,

		TitleScreen
	};
}

namespace Fonts
{
	enum class ID
	{
		Main
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif // RESOURCE_IDENTIFIERS_HPP
