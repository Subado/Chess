#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <Piece.hpp>
#include <Pawn.hpp>
#include <iostream>
#include <cmath>
#include <array>

#define DEBUG

class Game
{
	void processEvents();
	void render();

	public:
		Game();
		void run();
};

#endif // GAME_HPP_
