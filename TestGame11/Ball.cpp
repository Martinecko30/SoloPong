#include "Ball.h"
#include<iostream>

void Ball::update(sf::RectangleShape paddle, sf::Vector2f bounds, float deltaTime) {

    const float bx = body.getPosition().x + (body.getRadius() / 2);
    const float by = body.getPosition().y + body.getRadius();
    if (by > bounds.y) {
        reset();
    }
    else if (by < 0) {
        // top wall
        ballVelocity.x *= speedBuff;
        ballVelocity.y *= -speedBuff;
    }

    else if (bx > bounds.x) {
        // right wall
        ballVelocity.x *= -speedBuff;
        ballVelocity.y *= speedBuff;
    }
    else if (bx < 0) {
        // left wall
        ballVelocity.x *= -speedBuff;
        ballVelocity.y *= speedBuff;
    }

    if (by > paddle.getPosition().y &&
        bx < paddle.getPosition().x + paddle.getSize().x &&
        bx > paddle.getPosition().x
        ) {
        ballVelocity.x = ballVelocity.x;
        ballVelocity.y *= -speedBuff;
    }

	body.move(ballVelocity * deltaTime);

    //std::cout << body.getPosition().x << " " << body.getPosition().y << "\n";
}

void Ball::reset() {
    ballVelocity = sf::Vector2f(-60, 90);
    body.setPosition(300, 300);
    std::cout << "restart\n";
}

Ball::Ball() {
	ballVelocity = sf::Vector2f(-60, 90);
    speedBuff = 1.01f;
}

Ball::~Ball() {
	
}