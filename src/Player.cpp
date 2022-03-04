#include <Player.hpp>

Player::Player()
{
	m_keyBinding[sf::Keyboard::H] = Action::MoveLeft;
	m_keyBinding[sf::Keyboard::J] = Action::MoveDown;
	m_keyBinding[sf::Keyboard::K] = Action::MoveUp;
	m_keyBinding[sf::Keyboard::L] = Action::MoveRight;

	m_actionBinding[Action::MoveLeft];

	for (auto &pair : m_actionBinding)
	{
		pair.second.category = Category::Type::PlayerPiece;
	} }

void Player::handleRealtimeInput(CommandQueue &commands)
{
	for (const auto &pair : m_keyBinding)
	{
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
		{
			commands.push(m_actionBinding[pair.second]);
		}
	}
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//commands.push();
			}
			break;
		default:
			break;
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto i = m_keyBinding.begin(); i != m_keyBinding.end(); i++)
	{
		if (i->second == action)
		{
			m_keyBinding.erase(i);
		}
	}

	m_keyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignKey(Action action) const
{
	for (auto pair : m_keyBinding)
	{
		if (pair.second == action)
		{
			return pair.first;
		}
	}

	return sf::Keyboard::Key::Unknown;
}

void initActions()
{

}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
		case Action::MoveUp:
		case Action::MoveDown:
		case Action::MoveLeft:
		case Action::MoveRight:
			return true;

		default:
			return false;
	};
}
