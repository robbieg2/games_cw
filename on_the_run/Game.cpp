#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game()
:mWindow(sf::VideoMode(1920, 1080), "On The Run")
, mPlayer()
{
	mPlayerTexture.loadFromFile("bin/Debug/res/player/Player.png");
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setScale(sf::Vector2f(10, 10));
	mPlayer.setOrigin(sf::Vector2f(8, 8));
}

void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
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
		sf::Time deltaTime = clock.restart();
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(deltaTime);
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
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
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
	sf::Vector2f movement(0.f, 0.f);
	float movementSpeed = 200.f;
	if (pIsMovingUp)
		movement.y -= 1.f;
	if (pIsMovingDown)
		movement.y += 1.f;
	if (pIsMovingLeft)
		movement.x -= 1.f;
	if (pIsMovingRight)
		movement.x += 1.f;

	if (movement.x != 0.f || movement.y != 0.f)
	{
		movement = movement / std::sqrt(movement.x * movement.x + movement.y * movement.y);
	}

	mPlayer.move(movement * deltaTime.asSeconds() * movementSpeed);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}