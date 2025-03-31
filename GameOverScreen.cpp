//
// Created by matma on 12/7/2024.
//

#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        std::cerr << "Can't load font." << std::endl;
        return;
    }
    setupText();
}

void GameOverScreen::setupText() {
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(window.getSize().x / 2.f - gameOverText.getLocalBounds().width / 2.f,window.getSize().y / 2.f - gameOverText.getLocalBounds().height / 2.f - 50.f);

    promptText.setFont(font);
    promptText.setString("Press Esc to Quit");
    promptText.setCharacterSize(24);
    promptText.setFillColor(sf::Color::White);
    promptText.setPosition(window.getSize().x / 2.f - promptText.getLocalBounds().width / 2.f,window.getSize().y / 2.f + 20.f);
}

void GameOverScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(gameOverText, states);
    target.draw(promptText, states);
}
