//
// Created by matma on 12/7/2024.
//

#include "SplashScreen.h"
#include <iostream>

SplashScreen::SplashScreen(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        std::cerr << "Can't load font" << std::endl;
        return;
    }

    if (!splashImageTexture.loadFromFile("SplashScreenImageForSnake.png")) {
        std::cerr << "Can't load splash screen." << std::endl;
        return;
    }

    splashImage.setTexture(splashImageTexture);
    splashImage.setPosition(window.getSize().x / 2.f - splashImage.getGlobalBounds().width / 2.f,window.getSize().y / 2.f - splashImage.getGlobalBounds().height / 2.f);

    setupComponents();
}

void SplashScreen::setupComponents() {
    gameTitle.setFont(font);
    gameTitle.setString("Snek");
    gameTitle.setCharacterSize(48);
    gameTitle.setFillColor(sf::Color::Green);
    gameTitle.setStyle(sf::Text::Bold);
    gameTitle.setPosition(window.getSize().x / 2.f - gameTitle.getLocalBounds().width / 2.f,20.f);

    nameText.setFont(font);
    nameText.setString("Matvey Matsko");
    nameText.setCharacterSize(24);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition(window.getSize().x / 2.f - nameText.getLocalBounds().width / 2.f, 80.f);

    courseText.setFont(font);
    courseText.setString("CS 003A - CRN: 72623");
    courseText.setCharacterSize(24);
    courseText.setFillColor(sf::Color::White);
    courseText.setPosition(window.getSize().x / 2.f - courseText.getLocalBounds().width / 2.f,120.f);

    termText.setFont(font);
    termText.setString("Fall 2024");
    termText.setCharacterSize(24);
    termText.setFillColor(sf::Color::White);
    termText.setPosition(window.getSize().x / 2.f - termText.getLocalBounds().width / 2.f,160.f);

    startButton.setSize({200.f, 50.f});
    startButton.setFillColor(sf::Color::Blue);
    startButton.setPosition(window.getSize().x / 2.f - startButton.getSize().x / 2.f, window.getSize().y - startButton.getSize().y - 10.f);
}

bool SplashScreen::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        if (startButton.getGlobalBounds().contains(mousePos))
            return true;
    }
    return false;
}

void SplashScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(splashImage, states);
    target.draw(gameTitle, states);
    target.draw(nameText, states);
    target.draw(courseText, states);
    target.draw(termText, states);
    target.draw(startButton, states);
}
