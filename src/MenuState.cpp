#include <MenuState.hpp>

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
{
	m_backgroundSprite.setTexture(context.textures->
}

void MenuState::draw()
{
	sf::RenderWindow &window = *getContext().window;

	window.draw(m_backgroundSprite);

	for (sf::Text &option : m_options)
	{
		window.draw(option);
	}
}

bool MenuState::update(sf::Time dt)
{
	updateOptionText();

	return true;
}
