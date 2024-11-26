#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game()
:mWindow(sf::VideoMode(1920, 1080), "On The Run")// Sets screen size and title
, mPlayer()
{
	mPlayerTexture.loadFromFile("bin/Debug/res/player/PlayerMovingSpriteSheet.png");// Location of sprite
	// Setting player sprite position and size
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setTextureRect(sf::IntRect(0,0,30,30));// Takes a portion of the sprite sheet
	mPlayer.setScale(sf::Vector2f(10, 10));
	mPlayer.setOrigin(sf::Vector2f(8, 8));
}

void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
	// If a movement key is pressed then its corrosponding variable is set to true
	// References Game::processEvents()
	if (key == sf::Keyboard::W)
		pIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		pIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		pIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		pIsMovingRight = isPressed;
}

void Game::run()

{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;


	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{   
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			// Sets movement to true when a movement key is pressed
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
			// Sets movement to false when a movement key is released
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	// Sets default movement to nothing
	sf::Vector2f movement(0.f, 0.f);
	// Sets movement speed for when a key is pressed
	movementSpeed = 100.f;
	// Moves the player in the a direction depending on what/if a key is pressed
	if (pIsMovingUp)
		movement.y -= 1.f;
	if (pIsMovingDown)
		movement.y += 1.f;           
	if (pIsMovingLeft)
		movement.x -= 1.f;
	if (pIsMovingRight)
		movement.x += 1.f;

	//calculates movement trajectory
	mPlayer.move(movement * deltaTime.asSeconds() * movementSpeed);
}

// Renders the window
void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}