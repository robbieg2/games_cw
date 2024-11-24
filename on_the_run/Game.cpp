#include "Game.h"
#include <SFML/Graphics.hpp>

Game::Game()
:mWindow(sf::VideoMode(1920, 1080), "On The Run")
, mPlayer()
{
	mPlayerTexture.loadFromFile("res/player/Player.png");
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setScale(sf::Vector2f(10, 10));
	mPlayer.setOrigin(sf::Vector2f(8, 8));
}
void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}