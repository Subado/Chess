#include <Game.hpp>

Game::Game() : m_selectedPiece(nullptr)
{
	m_textures[0].loadFromFile("assets/images/black-pawn.png");
	m_possibleMoveTexture.loadFromFile("assets/images/transparent-circle.png");
	m_boardTexture.loadFromFile("assets/images/chess-board.png");
	m_boardSprite.setTexture(m_boardTexture);
	m_boardSprite.scale(sf::Vector2f(static_cast<float>(700)/m_boardTexture.getSize().x, static_cast<float>(700)/m_boardTexture.getSize().y));

	m_possibleMoveSprite.setTexture(m_possibleMoveTexture);
	m_possibleMoveSprite.setScale(m_boardSprite.getScale());

	m_lengthOfSquare = m_boardSprite.getGlobalBounds().width/8;

	m_pieces.push_back(std::vector<std::unique_ptr<Piece>>());
	m_pieces[0].push_back(std::make_unique<Pawn>(Pawn(&m_textures[0], m_boardSprite.getScale(), sf::Vector2u(6, 5), m_lengthOfSquare, 0, sf::Vector2i(0, -1), m_pieces)));
	m_pieces[0].push_back(std::make_unique<Pawn>(Pawn(&m_textures[0], m_boardSprite.getScale(), sf::Vector2u(7, 6), m_lengthOfSquare, 0, sf::Vector2i(0, -1), m_pieces)));

}

void Game::handleEvents()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_selectedPiece)
		{
			(*m_selectedPiece)->move(m_pieces, sf::Vector2u(trunc(sf::Mouse::getPosition().x / m_lengthOfSquare), trunc(sf::Mouse::getPosition().y / m_lengthOfSquare)), m_lengthOfSquare);
		}
		for (auto &i : m_pieces[0])
		{
			if ((sf::Mouse::getPosition().x >= i->getSprite().getPosition().x && sf::Mouse::getPosition().x <= i->getSprite().getPosition().x + i->getSprite().getGlobalBounds().width) &&
					(sf::Mouse::getPosition().y >= i->getSprite().getPosition().y && sf::Mouse::getPosition().y <= i->getSprite().getPosition().y + i->getSprite().getGlobalBounds().height))
			{
				m_selectedPiece = &i;
			}
		}
	}

}

void Game::draw(sf::RenderWindow &window)
{
	window.draw(m_boardSprite);
	for (auto &i : m_pieces)
	{
		for (auto &j : i)
		{
			window.draw(j->getSprite());
		}
	}
	if (m_selectedPiece)
	{

		for (auto &i : (*m_selectedPiece)->getPossibleMoves())
		{
			m_possibleMoveSprite.setPosition(m_lengthOfSquare*i.x, m_lengthOfSquare*i.y);
			window.draw(m_possibleMoveSprite);
		}
	}
}
