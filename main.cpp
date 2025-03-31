#include <SFML/Graphics.hpp>
#include "SnakeBody.h"
#include "Fruit.h"
#include "GameView.h"
#include "Controller.h"
#include "GameOverScreen.h"
#include "SplashScreen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snek", sf::Style::Close);
    window.setFramerateLimit(60);

    SplashScreen splashScreen(window);

    bool splashDone = false;
    while (window.isOpen() && !splashDone) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            splashDone = splashScreen.handleEvent(event);
        }

        window.clear();
        window.draw(splashScreen);
        window.display();
    }

    ////////////////////////////////////////////////////////////////

    float segmentSize = 50.f;

    SnakeBody snakeHead({segmentSize, segmentSize});
    snakeHead.setSegmentSize(segmentSize);
    snakeHead.setPosition({0, 0});
    snakeHead.setFillColor(sf::Color::Yellow);

    Fruit fruit(segmentSize / 2, sf::Color::Red);
    fruit.setPosition({100, 100});

    GameView gameView(window);
    Controller controller(snakeHead, fruit, window);

    GameOverScreen gameOverScreen(window);
    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!gameOver)
                controller.handleInput();

        }

        if (gameOver) {
            window.clear();
            window.draw(gameOverScreen);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

        }
        else {
            controller.update();

            window.clear();
            gameView.update(snakeHead, fruit);

            if (Collision::checkBoundaryCollision(snakeHead, window) ||
                Collision::checkBodyCollision(snakeHead.getBody(), snakeHead.getPosition(), segmentSize)) {
                gameOver = true;
            }
        }
    }

    return 0;
}
