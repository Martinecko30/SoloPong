#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
	sf::Vector2f ballVelocity;

	float speedBuff;

public:
	sf::CircleShape body;

	void update(sf::RectangleShape paddle, sf::Vector2f bounds, float deltaTime);

	void reset();

	Ball();
	~Ball();
};