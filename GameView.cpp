//
// Created by matma on 12/7/2024.
//

#include "GameView.h"

GameView::GameView(sf::RenderWindow& window) : window(window) {}

void GameView::update(SnakeBody& snake, Fruit& fruit) {
    window.clear();
    fruit.draw(window);
    window.draw(snake);

    for (const auto& segment : snake.getBody())
        window.draw(segment);

    window.display();
}
