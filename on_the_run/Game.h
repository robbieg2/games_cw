#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

class Game
{
	public:
				Game();
		void	run();
			
	private:
		void	processEvents();
		void	update();
		void	render();
		
	private:
		sf::RenderWindow mWindow;

		sf::Sprite mPlayer;

		sf::Texture mPlayerTexture;
};

int main()
{
	Game game;
	game.run();
}