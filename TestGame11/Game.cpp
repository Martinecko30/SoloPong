#include "Game.h"
#include<math.h>



void Game::initVariables() {
	this->window = nullptr;
}

void Game::initWindow() {
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Test Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

void Game::initEnemies() {
    /*this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color(100, 0, 255));
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);*/

    this->ball.body.setPosition(50.f, 50.f);
    this->ball.body.setRadius(10);
    this->ball.body.setFillColor(sf::Color::White);

    this->player.body.setPosition(window->getSize().x / 2.f, window->getSize().y - 40.f);
    this->player.body.setSize(sf::Vector2f(100.f, 10.f));
    this->player.body.setFillColor(sf::Color::White);
}



// Constructor / Destructor
Game::Game() {
	this->initVariables();
	this->initWindow();
    this->initEnemies();
}

Game::~Game() {
	delete this->window;
}



// Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}



// Functions
void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;



        default:
            break;
        }
    }
}

void Game::update(float deltaTime)
{
    this->pollEvents();

    sf::Vector2f bounds = sf::Vector2f(this->window->getSize().x + 0.f, this->window->getSize().y);

    ball.update(player.body, bounds, deltaTime);
    player.update(bounds);

    // Update mouse position

    // Relative to the screen
    //std::cout << "Mouse position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";

    // Relative to the window
    //std::cout << "Mouse position: " 
    //    << sf::Mouse::getPosition(*this->window).x << " " 
    //    << sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render()
{


    this->window->clear();

    // --- Draw game ---

    this->window->draw(this->ball.body);
    this->window->draw(this->player.body);


    // ---

    this->window->display();
}