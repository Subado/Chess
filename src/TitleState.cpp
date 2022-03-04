#include <ResourceHolder.hpp>
#include <TitleState.hpp>
#include <Utility.hpp>

TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context)
{
	m_backgroundSprite.setTexture(context.textures->get(Textures::ID::TitleScreen));

	m_text.setFont(context.fonts->get(Fonts::ID::Main));
	m_text.setString("Press any key to start");
	m_text.setOutlineColor(sf::Color(0xECEFF4));
	m_text.setFillColor(sf::Color(0xECEFF4));
	centerOrigin<sf::Text>(m_text);
	m_text.setPosition(context.window->getView().getSize() / 2.f);
}

void TitleState::draw()
{
	sf::RenderWindow &window = *getContext().window;

	window.draw(m_backgroundSprite);

	if (m_showText)
	{
		window.draw(m_text);
	}
}

bool TitleState::update(sf::Time dt)
{
	m_textEffectTime += dt;

	if (m_textEffectTime >= sf::seconds(0.5f))
	{
		m_showText = !m_showText;
		m_textEffectTime = sf::Time::Zero;
	}

	return true;
}

#include <iostream>
bool TitleState::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
	{
		requestStackPop();
		std::cout << "meow\n";
		requestStackPush(States::ID::Menu);
	}

	return true;
}
