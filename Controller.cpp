//
// Created by matma on 12/4/2024.
//

#include "Controller.h"

Controller::Controller(SnakeBody& snake, Fruit& fruit, sf::RenderWindow& window)
    : snake(snake), fruit(fruit), window(window) {}


void Controller::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        snake.eventHandler(window);
    }
}


void Controller::update() {
    if (clock.getElapsedTime().asSeconds() >= 0.5f) {
        snake.update(window, fruit);
        clock.restart();
    }
}