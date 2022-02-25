#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Window/Event.hpp>
#include <CommandQueue.hpp>

class Player
{
public:
	void handleRealtimeInput(CommandQueue &commands);
	void handleEvent(const sf::Event &event, CommandQueue &commands);
};

#endif // PLAYER_HPP
