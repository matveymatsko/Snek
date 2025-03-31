//
// Created by matma on 11/27/2024.
//

#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "Fruit.h"
#include <vector>
#include <iostream>

class SnakeBody : public sf::RectangleShape {

private:
    float speed;
    sf::Keyboard::Key up, down, left, right;
    enum Direction {UP, DOWN, LEFT, RIGHT, NONE};
    Direction currentDirection;
    bool isMoving;
    std::vector<sf::RectangleShape> body;
    void moveHead();
    void moveBody();

public:
    SnakeBody(const sf::Vector2f& size);
    void eventHandler(sf::RenderWindow &window);
    void update(sf::RenderWindow &window, Fruit& fruit);
    void setSegmentSize(float dimension);
    void addBody();
    const std::vector<sf::RectangleShape>& getBody() const;

};

#endif //SNAKEBODY_H
