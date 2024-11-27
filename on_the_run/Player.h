#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Player {
public:
	Player();

	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	void updateAnimationMovement();

	void updateMovement(sf::Time deltaTime);

	sf::Sprite& getSprite() { return mPlayer; }

private:
	sf::Sprite mPlayer;

	sf::Texture mPlayerTexture;

	float movementSpeed;

	bool pIsMovingUp;
	bool pIsMovingDown;
	bool pIsMovingLeft;
	bool pIsMovingRight;

	int currentFrame;
	int frameCounter;
};