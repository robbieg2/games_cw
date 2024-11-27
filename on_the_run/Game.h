#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
	public:
				Game();
		void	run();
			
	private:
		void	processEvents();
		void	update(sf::Time deltaTime);
		void	render();
		
	private:
		sf::RenderWindow mWindow;
		Player mPlayer;
		sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};

int main()
{
	Game Game;
	Game.run();
}