#include "Player.h"

void Player::update(sf::Vector2f bounds) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (body.getPosition().x - 1 < 0) return;
		this->body.setPosition(this->body.getPosition().x - speed, this->body.getPosition().y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (body.getPosition().x + body.getSize().x + 1 > bounds.x) return;
		this->body.setPosition(this->body.getPosition().x + speed, this->body.getPosition().y);
	}
}

Player::Player() {
	speed = 2.f;
}

Player::~Player() {
	
}