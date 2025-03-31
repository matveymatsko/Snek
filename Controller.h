//
// Created by matma on 12/4/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SnakeBody.h"
#include "Fruit.h"
#include <SFML/Graphics.hpp>

class Controller {

private:
    SnakeBody& snake;
    Fruit& fruit;
    sf::RenderWindow& window;
    sf::Clock clock;

public:
    Controller(SnakeBody& snake, Fruit& fruit, sf::RenderWindow& window);
    void handleInput();
    void update();

};

#endif //CONTROLLER_H
