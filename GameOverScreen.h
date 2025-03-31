//
// Created by matma on 12/7/2024.
//

#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>


class GameOverScreen : public sf::Drawable {

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text promptText;


public:
    explicit GameOverScreen(sf::RenderWindow& window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setupText();


};

#endif //GAMEOVERSCREEN_H
