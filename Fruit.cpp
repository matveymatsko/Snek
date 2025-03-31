//
// Created by matma on 11/27/2024.
//

#include "Fruit.h"

Fruit::Fruit(float radius, sf::Color color) : sf::CircleShape(radius) {
    setFillColor(color);
}

void Fruit::respawn(sf::RenderWindow &window, const std::vector<sf::RectangleShape>& snakeBody) {
    bool validPosition = false;
    sf::Vector2f newFruitPosition;

    while (!validPosition) {
        newFruitPosition.x = (rand() % (static_cast<int>(window.getSize().x) / static_cast<int>(getRadius() * 2))) * static_cast<int>(getRadius() * 2);
        newFruitPosition.y = (rand() % (static_cast<int>(window.getSize().y) / static_cast<int>(getRadius() * 2))) * static_cast<int>(getRadius() * 2);

        validPosition = true;

        for (const auto& segment : snakeBody) {
            if (segment.getGlobalBounds().contains(newFruitPosition)) {
                validPosition = false;
                break;
            }
        }
    }
    setPosition(newFruitPosition);
}

void Fruit::draw(sf::RenderWindow &window) {
    window.draw(*this);
}
