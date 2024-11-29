#include "Police.h"
#include "Player.h"
#include <cmath>
#include <SFML/Graphics.hpp>

Police::Police()
	:	currentFrame(0),
		frameCounter(0),
		aiSpeed(300.f),
		aiTurnSpeed(90.f),
		mRotation(0.f),
		degreseToRadian(3.14159265f / 180.f)
{
	mPoliceTexture.loadFromFile("bin/Debug/res/police/PoliceMovingSpriteSheet.png");// Location of sprite
	// Setting police sprite position and size
	mPolice.setTexture(mPoliceTexture);
	mPolice.setTextureRect(sf::IntRect(0, 0, 30, 30));// Takes a portion of the sprite sheet
	mPolice.setScale(sf::Vector2f(10, 10));
	mPolice.setOrigin(sf::Vector2f(15, 8));
	mPolice.setPosition(1000.f, 1000.f);
}

void Police::updateAnimationMovement()
{

	mPolice.setTextureRect(sf::IntRect(30 * currentFrame, 0, 30, 30));

	if (frameCounter == 15)
	{
		currentFrame = (currentFrame + 1) % 2;
		frameCounter = 0;
	}
	frameCounter++;
}

float Police::normalizeAngle(float angle)
{
	while (angle > 180.f) angle -= 360.f;
	while (angle < -180.f) angle += 360.f;
	return angle;
}

void Police::followPlayer(const Player& player, float deltaTime)
{
	sf::Vector2f direction = player.getPosition() - mPolice.getPosition();
	float angleToPlayer = std::atan2(direction.y, direction.x) * 180.f / 3.14159265f;

	angleToPlayer += 90.f;

	float angleDifference = normalizeAngle(angleToPlayer - mRotation);

	if (std::abs(angleDifference) > 1.f)
	{
		if (angleDifference > 0)
		{
			mRotation += aiTurnSpeed * deltaTime;
		}
		else
		{
			mRotation -= aiTurnSpeed * deltaTime;
		}
		mRotation = normalizeAngle(mRotation);
	}
	else
	{
		float radianRotation = (mRotation - 90.f) * degreseToRadian;
		sf::Vector2f velocity(std::cos(radianRotation) * aiSpeed,
							  std::sin(radianRotation) * aiSpeed);
		mPolice.move(velocity * deltaTime);
		updateAnimationMovement();
	}
	mPolice.setRotation(mRotation);
}