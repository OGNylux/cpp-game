//
// Created by nylux on 01.04.2024.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    //font.loadFromFile(FONT);

    startButton.setSize(sf::Vector2f(285, 75));
    startButton.setFillColor(sf::Color::Red);
    startButton.setPosition(1200.0f / 2 - startButton.getGlobalBounds().width / 2, 380);

    //startText.setFont(font);
    startText.setString("Starten");
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(1200.0f / 2 - (startText.getGlobalBounds().width / 2), 382);

    exitButton.setSize(sf::Vector2f(285, 75));
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(1200.0f / 2 - exitButton.getGlobalBounds().width / 2, 500);

    exitText.setFont(font);
    exitText.setString("Beenden");
    exitText.setCharacterSize(50);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(1200.0f / 2 - (exitText.getGlobalBounds().width / 2), 502);

    background.setTexture(texture);
}

void MainMenu::handleInput(sf::RenderWindow &window) {
    const sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // Check if mouse is over the startButton
    if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const sf::Color originalColor = startButton.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        startButton.setFillColor(newColor);
    } else {
        startButton.setFillColor(sf::Color::Red);
    }

    // Check if mouse is over the exitButton
    if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        const sf::Color originalColor = exitButton.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        exitButton.setFillColor(newColor);
    } else {
        exitButton.setFillColor(sf::Color::Red);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            //pause = false;
            printf("startButton\n");
        }
        if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            printf("exitButton\n");
            //window.close();
        }
    }
}

void MainMenu::update(float dt) {
}

void MainMenu::draw(sf::RenderTarget &target) const {
    target.draw(background);

    target.draw(startButton);
    target.draw(startText);

    target.draw(exitButton);
    target.draw(exitText);
}