//
// Created by nylux on 09.04.2024.
//

#include "DeathMenu.h"
#include "SFML/Window/Mouse.hpp"
#include "../Game.h"

DeathMenu::DeathMenu()
{
    background.setSize(sf::Vector2f(100, 100));
    background.setFillColor(sf::Color(0, 0, 0, 150));

    title.setString("You died!");
    title.setCharacterSize(100);
    title.scale(0.05f, 0.05f);
    title.setFillColor(sf::Color::White);
    title.setPosition(38, 15);

    startButton.setSize(sf::Vector2f(25, 7));
    startButton.setFillColor(sf::Color(255, 255, 255, 180));
    startButton.setPosition(100.0f / 2 - startButton.getGlobalBounds().width / 2, 30);

    startText.setString("Resume");
    startText.setCharacterSize(50);
    startText.scale(0.1f, 0.1f);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition((100.0f / 2 - startButton.getGlobalBounds().width / 2)+3, 30.1);

    exitButton.setSize(sf::Vector2f(25, 7));
    exitButton.setFillColor(sf::Color(255, 255, 255, 180));
    exitButton.setPosition(100.0f / 2 - exitButton.getGlobalBounds().width / 2, 40);

    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.scale(0.1f, 0.1f);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition((100.0f / 2 - exitButton.getGlobalBounds().width / 2)+7, 40.1);
}

void DeathMenu::handleInput(sf::RenderWindow &window)
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
        if(startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            Game::getPlayer().setDeadState(false);
            Game::restart();
        }
        if(exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) Game::setInGame(false);
    }
}

void DeathMenu::draw(Renderer& renderer)
{
    sf::Font font;
    font.loadFromFile("assets/yoster.ttf");

    title.setFont(font);
    startText.setFont(font);
    exitText.setFont(font);
    renderer.target.draw(background);
    renderer.target.draw(title);
    renderer.target.draw(startButton);
    renderer.target.draw(startText);
    renderer.target.draw(exitButton);
    renderer.target.draw(exitText);
}
