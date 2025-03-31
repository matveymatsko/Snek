//
// Created by matma on 12/7/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "SnakeBody.h"
#include "Fruit.h"

class GameView {

private:
    sf::RenderWindow& window;

public:
    GameView(sf::RenderWindow& window);
    void update(SnakeBody& snake, Fruit& fruit);

};

#endif //GAMEVIEW_H
