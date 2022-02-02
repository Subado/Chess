#include <Game.hpp>

Game::Game() : m_selectedSquare(nullptr)
{
	m_textures.load(Textures::ID::Board, "assets/images/chess-board.png");
	m_textures.load(Textures::ID::PossibleMove, "assets/images/transparent-circle.png");
	m_textures.load(Textures::ID::Pawn, "assets/images/black-pawn.png");

	m_boardSprite.setTexture(m_textures.get(Textures::ID::Board));
	m_boardSprite.scale(sf::Vector2f(static_cast<float>(700)/m_textures.get(Textures::ID::Board).getSize().x, static_cast<float>(700)/m_textures.get(Textures::ID::Board).getSize().y));

	m_possibleMoveSprite.setTexture(m_textures.get(Textures::ID::PossibleMove));
	m_possibleMoveSprite.setScale(m_boardSprite.getScale());

	m_lengthOfSquare = m_boardSprite.getGlobalBounds().width/8;

	m_boardOfSquares[6][5] = std::make_shared<Pawn>(Pawn(m_textures.get(Textures::ID::Pawn), m_boardSprite.getScale(), sf::Vector2u(6, 5), m_lengthOfSquare, 0, sf::Vector2i(0, -1), m_boardOfSquares));
	/* m_pieces[0].push_back(std::make_unique<Pawn>(Pawn(m_textures.get(Textures::ID::Pawn), m_boardSprite.getScale(), sf::Vector2u(6, 5), m_lengthOfSquare, 0, sf::Vector2i(0, -1), m_pieces)));
	 * m_pieces[0].push_back(std::make_unique<Pawn>(Pawn(m_textures.get(Textures::ID::Pawn), m_boardSprite.getScale(), sf::Vector2u(7, 6), m_lengthOfSquare, 0, sf::Vector2i(0, -1), m_pieces))); */

}

void Game::handleMouseInput(const sf::RenderWindow &window)
{
	std::cout << "Mouse: x=" << sf::Mouse::getPosition(window).x << " y=" << sf::Mouse::getPosition(window).y << '\n';
	if (m_selectedSquare)
	{
		(**m_selectedSquare).move(m_boardOfSquares, sf::Vector2u(trunc(sf::Mouse::getPosition(window).x / m_lengthOfSquare), trunc(sf::Mouse::getPosition(window).y / m_lengthOfSquare)), m_lengthOfSquare);
	}
	for (auto &i : m_boardOfSquares)
	{
		for (auto &j : i)
		{
			if (j.isNotEmpty())
			{
				if ((sf::Mouse::getPosition(window).x >= (*j).getSprite().getPosition().x && sf::Mouse::getPosition(window).x <= (*j).getSprite().getPosition().x + (*j).getSprite().getGlobalBounds().width) &&
						(sf::Mouse::getPosition(window).y >= (*j).getSprite().getPosition().y && sf::Mouse::getPosition(window).y <= (*j).getSprite().getPosition().y + (*j).getSprite().getGlobalBounds().height))
				{
					m_selectedSquare = &j;
				}
			}
		}
	}
}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(m_boardSprite);
	for (auto &i : m_boardOfSquares)
	{
		for (auto &j : i)
		{
			if (j.isNotEmpty())
			window.draw((*j).getSprite());
		}
	}
	if (m_selectedSquare)
	{
		for (auto &i : (**m_selectedSquare).getPossibleMoves())
		{
			m_possibleMoveSprite.setPosition(m_lengthOfSquare*i.x, m_lengthOfSquare*i.y);
			std::cout << "x=" << i.x << " y=" << i.y << '\n';
			// std::cin.get();
			window.draw(m_possibleMoveSprite);
		}
	}
		std::cout << "Pawn: x=" << (*m_boardOfSquares[6][5]).getSprite().getPosition().x << " y=" << (*m_boardOfSquares[6][5]).getSprite().getPosition().y << '\n' <<
			"x=" << (*m_boardOfSquares[6][5]).getSprite().getPosition().x + (*m_boardOfSquares[6][5]).getSprite().getGlobalBounds().width << " y=" << (*m_boardOfSquares[6][5]).getSprite().getPosition().y + (*m_boardOfSquares[6][5]).getSprite().getGlobalBounds().height << '\n';
		std::cout << "Window size: x=" << window.getSize().x << " y=" << window.getSize().y << '\n';
		std::cout << "selectedPiece=" << m_selectedSquare << '\n';
}
