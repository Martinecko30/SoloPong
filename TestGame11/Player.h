#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	float speed;

public:
	sf::RectangleShape body;

	void update(sf::Vector2f bounds);

	Player();
	~Player();
};