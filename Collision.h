//
// Created by matma on 12/7/2024.
//

#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

class Collision {
public:
    static bool checkBoundaryCollision(const sf::RectangleShape &shape, const sf::RenderWindow &window);
    static bool checkEaten(const sf::RectangleShape &head, const sf::CircleShape &fruit);
    static bool checkBodyCollision(const std::vector<sf::RectangleShape>& body, const sf::Vector2f& headPosition, float headSize);
};

#endif //COLLISION_H
