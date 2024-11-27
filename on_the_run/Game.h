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
		sf::Time TimePerFrame;

		sf::Texture mBackgroundTexture;
		sf::Sprite mBackgroundSprite;


		Player mPlayer;
};

int main()
{
	Game Game;
	Game.run();
}