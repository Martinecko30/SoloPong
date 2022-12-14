#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"Player.h"
#include"Ball.h"


/*
	Class for game engine.
*/

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	sf::RectangleShape enemy;
	Player player;
	Ball ball;


	// Private functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:
	// Constructos / Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void update(float deltaTime);
	void render();
};