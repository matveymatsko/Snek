//
// Created by matma on 12/7/2024.
//

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>

class SplashScreen : public sf::Drawable {

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text gameTitle;
    sf::Text nameText;
    sf::Text courseText;
    sf::Text termText;
    sf::RectangleShape startButton;
    sf::Texture splashImageTexture;
    sf::Sprite splashImage;

public:
    explicit SplashScreen(sf::RenderWindow& window);
    bool handleEvent(const sf::Event& event);
    void setupComponents();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //SPLASHSCREEN_H
