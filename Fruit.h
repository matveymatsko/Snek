//
// Created by matma on 11/27/2024.
//

#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include <vector>

class Fruit : public sf::CircleShape {
public:
    Fruit(float radius, sf::Color color);
    void respawn(sf::RenderWindow &window, const std::vector<sf::RectangleShape>& snakeBody);
    void draw(sf::RenderWindow &window);
};

#endif //FRUIT_H
