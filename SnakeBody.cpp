//
// Created by matma on 11/27/2024.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody(const sf::Vector2f& size)
    : sf::RectangleShape(size), speed(2.f), up(sf::Keyboard::W), down(sf::Keyboard::S), left(sf::Keyboard::A), right(sf::Keyboard::D),
      currentDirection(NONE), isMoving(false) {
    setFillColor(sf::Color::Yellow);
}

void SnakeBody::eventHandler(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(up) && currentDirection != DOWN) {
        currentDirection = UP;
        isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(down) && currentDirection != UP) {
        currentDirection = DOWN;
        isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(left) && currentDirection != RIGHT) {
        currentDirection = LEFT;
        isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(right) && currentDirection != LEFT) {
        currentDirection = RIGHT;
        isMoving = true;
    }
}

void SnakeBody::update(sf::RenderWindow& window, Fruit& fruit) {
    if (!isMoving)
        return;

    if (Collision::checkBoundaryCollision(*this, window)) {
        isMoving = false;
        std::cout << "Game Over: Collision with boundary" << std::endl;
        return;
    }

    if (Collision::checkEaten(*this, fruit)) {
        addBody();
        fruit.respawn(window, body);
    }

    moveBody();
    moveHead();

    if (Collision::checkBodyCollision(body, getPosition(), getSize().x)) {
        isMoving = false;
        std::cout << "Game Over: Collision with body" << std::endl;
    }
}

void SnakeBody::moveHead() {
    sf::Vector2f bodySize = getSize();
    switch (currentDirection) {
        case UP:
            move(0, -bodySize.y);
        break;
        case DOWN:
            move(0, bodySize.y);
        break;
        case LEFT:
            move(-bodySize.x, 0);
        break;
        case RIGHT:
            move(bodySize.x, 0);
        break;
        default:
            break;
    }
}

void SnakeBody::moveBody() {
    if (!body.empty()) {
        for (int i = body.size() - 1; i > 0; --i) {
            body[i].setPosition(body[i - 1].getPosition());
        }
        body[0].setPosition(getPosition());
    }
}

void SnakeBody::addBody() {
    sf::RectangleShape newSegment(getSize());
    newSegment.setFillColor(sf::Color::Green);

    if (!body.empty())
        newSegment.setPosition(body.back().getPosition());

    else
        newSegment.setPosition(getPosition());

    body.push_back(newSegment);
}

void SnakeBody::setSegmentSize(float dimension) {
    setSize({dimension, dimension});

    for (auto& segment : body)
        segment.setSize({dimension, dimension});

}

const std::vector<sf::RectangleShape>& SnakeBody::getBody() const {
    return body;
}
