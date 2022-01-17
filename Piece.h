#include <SFML/Graphics.hpp>

class Piece
{
	sf::Texture texture;
public:
	sf::Sprite sprite;
	Piece(const sf::Vector2f &scale, const std::string &img, const sf::Vector2f &position, const double &k);
	void move(const sf::Vector2f &position, const double &k);
};
