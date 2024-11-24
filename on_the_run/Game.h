#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	public:
				Game();
		void	run();


		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
			
	private:
		void	processEvents();
		void	update(sf::Time deltaTime);
		void	render();
		
	private:
		sf::RenderWindow mWindow;
		sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

		sf::Sprite mPlayer;

		sf::Texture mPlayerTexture;

		bool pIsMovingUp;
		bool pIsMovingDown;
		bool pIsMovingLeft;
		bool pIsMovingRight;
};

int main()
{
	Game game;
	game.run();
}