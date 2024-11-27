#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

Player::Player()
	:	movementSpeed(100.f),
		pIsMovingUp(false),
		pIsMovingDown(false),
		pIsMovingLeft(false),
		pIsMovingRight(false)
{
	mPlayerTexture.loadFromFile("bin/Debug/res/player/PlayerMovingSpriteSheet.png");// Location of sprite
	// Setting player sprite position and size
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setTextureRect(sf::IntRect(0, 0, 30, 30));// Takes a portion of the sprite sheet
	mPlayer.setScale(sf::Vector2f(10, 10));
	mPlayer.setOrigin(sf::Vector2f(15, 8));
	mPlayer.setPosition(100.f, 100.f);
}

void Player::handlePlayerInput(sf::Keyboard::Key key,
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

void Player::updateMovement(sf::Time deltaTime)
{
	// Sets default movement to nothing
	sf::Vector2f movement(0.f, 0.f);
	// Sets movement speed for when a key is pressed
	movementSpeed = 100.f;

	float rotation = mPlayer.getRotation();
	float angleInRadians = rotation * (3.14159f / 180.f);

	// Moves the player in the a direction depending on what/if a key is pressed
	if (pIsMovingUp) {
		movement.x = 0.f;
		movement.y = -1.f;
		mPlayer.setOrigin(sf::Vector2f(15, 8));
	}
	if (pIsMovingDown) {
		movement.x = 0.f;
		movement.y = 1.f;
		mPlayer.setOrigin(sf::Vector2f(15, 15));
	}
	if (pIsMovingLeft) {
		mPlayer.rotate(-90.f * deltaTime.asSeconds());
	}
	if (pIsMovingRight) {
		mPlayer.rotate(90.f * deltaTime.asSeconds());
	}

	if (movement.x != 0.f || movement.y != 0.f)
	{
		float rotation = mPlayer.getRotation();
		float angleInRadians = rotation * (3.12159f / 180.f);

		float cosRotation = cos(angleInRadians);
		float sinRotation = sin(angleInRadians);

		sf::Vector2f rotatedMovement;
		rotatedMovement.x = movement.x * cosRotation - movement.y * sinRotation;
		rotatedMovement.y = movement.x * sinRotation + movement.y * cosRotation;

		//calculates movement trajectory
		mPlayer.move(rotatedMovement * deltaTime.asSeconds() * movementSpeed);
	}
}