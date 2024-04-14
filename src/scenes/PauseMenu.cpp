//
// Created by a3445 on 02.04.2024.
//

#include "PauseMenu.h"
#include "SFML/Window/Mouse.hpp"
#include "../Game.h"

PauseMenu::PauseMenu()
{
    printf("PauseMenu::PauseMenu()\n");
    font.loadFromFile("assets/yoster.ttf");

    background.setSize(sf::Vector2f(100, 100));
    background.setFillColor(sf::Color(0, 0, 0, 150));

    title.setFont(font);
    title.setString("Paused");
    title.setCharacterSize(100);
    title.scale(0.1f, 0.1f);
    title.setFillColor(sf::Color::White);

    startButton.setSize(sf::Vector2f(25, 7));
    startButton.setFillColor(sf::Color(255, 255, 255, 180));
    startButton.setPosition(100.0f / 2 - startButton.getGlobalBounds().width / 2, 30);

    startText.setFont(font);
    startText.setString("Resume");
    startText.setCharacterSize(50);
    startText.scale(0.1f, 0.1f);
    startText.setFillColor(sf::Color::Black);

    exitButton.setSize(sf::Vector2f(25, 7));
    exitButton.setFillColor(sf::Color(255, 255, 255, 180));
    exitButton.setPosition(100.0f / 2 - exitButton.getGlobalBounds().width / 2, 40);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.scale(0.1f, 0.1f);
    exitText.setFillColor(sf::Color::Black);
}

void PauseMenu::handleInput(sf::RenderWindow &window)
{
    const sf::Vector2i mousePosition = {sf::Mouse::getPosition(window).x / 12, sf::Mouse::getPosition(window).y / 12};

    // Check if mouse is over the startButton
    if(startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        const sf::Color originalColor = startButton.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 120);
        startButton.setFillColor(newColor);
    }
    else startButton.setFillColor(sf::Color(255, 255, 255, 180));


    // Check if mouse is over the exitButton
    if(exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        const sf::Color originalColor = exitButton.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 120);
        exitButton.setFillColor(newColor);
    }
    else exitButton.setFillColor(sf::Color(255, 255, 255, 180));

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) Game::setPaused(false);
        if(exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) Game::setInGame(false);
    }
}

void PauseMenu::draw(Renderer& renderer) const
{
    printf("PauseMenu::draw()\n");
    renderer.target.draw(background);
    renderer.target.draw(title);
    renderer.target.draw(startButton);
    renderer.target.draw(startText);
    renderer.target.draw(exitButton);
    renderer.target.draw(exitText);
}