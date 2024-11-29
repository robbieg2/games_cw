#pragma once
#include "Player.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Police {
public:
	Police();

	void updateAnimationMovement();
	void followPlayer(const Player& player, float deltaTime);

	sf::Sprite& getSprite() { return mPolice; }

private:
	sf::Sprite mPolice;
	sf::Texture mPoliceTexture;

	float aiSpeed;
	float aiTurnSpeed;
	float mRotation;
	float degreseToRadian;

	int currentFrame;
	int frameCounter;

	float normalizeAngle(float angle);
};