#include <SFML/Graphics/RenderTarget.hpp>
#include <Piece.hpp>

Textures::ID& operator++(Textures::ID &id )
{
	using IntType = typename std::underlying_type<Piece::Color>::type;
	id = static_cast<Textures::ID>( static_cast<IntType>(id) + 1 );
	return id;
}

Textures::ID operator++( Textures::ID &id, int ) {
	Textures::ID result = id;
	++id;
	return result;
}

Textures::ID& operator+=(Textures::ID &id, int addend)
{
	using IntType = typename std::underlying_type<Piece::Color>::type;
	id = static_cast<Textures::ID>( static_cast<IntType>(id) + addend );
	return id;
}

Textures::ID toTextureID(Piece::Color color, Piece::Type type)
{
	enum Textures::ID id = Textures::ID::WhitePawn;

	switch (color)
	{
		case Piece::Color::Yellow:
			id += 6;
		case Piece::Color::Green:
			id += 6;
		case Piece::Color::Blue:
			id += 6;
		case Piece::Color::Red:
			id += 6;
		case Piece::Color::Black:
			id += 6;
		case Piece::Color::White:
			break;
	}
	switch (type)
	{

		case Piece::Type::King:
			++id;
		case Piece::Type::Queen:
			++id;
		case Piece::Type::Rook:
			++id;
		case Piece::Type::Bishop:
			++id;
		case Piece::Type::Knight:
			++id;
		case Piece::Type::Pawn:
			break;
	}

	return id;
}

Piece::Piece(const TextureHolder &textures, uint8_t position, uint8_t team, Color color, Type type)
	: m_position (position),
	m_team (team),
	m_sprite(textures.get(toTextureID(color, type)))
{
	textures.get(toTextureID(color, type));
    sf::FloatRect bounds = m_sprite.getLocalBounds();
	m_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

uint8_t Piece::getPosition() const
{
	return m_position;
}


uint8_t Piece::getTeam() const
{
	return m_team;
}

Piece::~Piece()
{
}


void Piece::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
