//
// Created by matma on 12/7/2024.
//


#include "Collision.h"

bool Collision::checkBoundaryCollision(const sf::RectangleShape &shape, const sf::RenderWindow &window) {
    sf::Vector2f position = shape.getPosition();
    sf::Vector2f size = shape.getSize();
    sf::Vector2u windowSize = window.getSize();

    if (position.x < 0 || position.x + size.x > windowSize.x || position.y < 0 || position.y + size.y > windowSize.y)
        return true;
    return false;
}

bool Collision::checkEaten(const sf::RectangleShape &head, const sf::CircleShape &fruit) {
    if (head.getGlobalBounds().intersects(fruit.getGlobalBounds()))
        return true;
    return false;
}

bool Collision::checkBodyCollision(const std::vector<sf::RectangleShape>& body, const sf::Vector2f& headPosition, float headSize) {
    for (int i = 1; i < body.size(); i++) {
        sf::Vector2f bodyPos = body[i].getPosition();
        sf::Vector2f bodySize = body[i].getSize();

        if (headPosition.x < bodyPos.x + bodySize.x && headPosition.x + headSize > bodyPos.x && headPosition.y < bodyPos.y + bodySize.y && headPosition.y + headSize > bodyPos.y)
            return true;
    }
    return false;
}
