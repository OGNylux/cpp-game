//
// Created by nylux on 01.04.2024.
//

#include <iostream>
#include "MainMenu.h"
#include "../Game.h"
#include "../Resources.h"

MainMenu::MainMenu()
{
    font.loadFromFile("assets/yoster.ttf");

    title.setFont(font);
    title.setString("Just Another Platformer");
    title.setCharacterSize(10);
    title.scale(0.035f, 0.035f);
    title.setFillColor(sf::Color::White);
    title.setPosition(0, 0);

    startButton.setSize(sf::Vector2f(11, 7));
    startButton.setFillColor(sf::Color(255, 255, 255, 0));

    startText.setFont(font);
    startText.setString("Play");
    startText.setCharacterSize(50);
    startText.scale(0.1f, 0.1f);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(4,25);

    exitButton.setSize(sf::Vector2f(11, 7));
    exitButton.setFillColor(sf::Color(255, 255, 255, 0));

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(50);
    exitText.scale(0.1f, 0.1f);
    exitText.setFillColor(sf::Color::White);
}

void MainMenu::handleInput(sf::RenderWindow &window)
{
    const sf::Vector2i mousePosition = {sf::Mouse::getPosition(window).x / 12, sf::Mouse::getPosition(window).y / 12};

    // Check if mouse is over the startButton
    if(startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        const sf::Color originalColor = startText.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        startText.setFillColor(newColor);
    }
    else startText.setFillColor(sf::Color(255, 255, 255, 255));

    // Check if mouse is over the exitButton
    if(exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        const sf::Color originalColor = exitText.getFillColor();
        const sf::Color newColor(originalColor.r, originalColor.g, originalColor.b, 180);
        exitText.setFillColor(newColor);
    }
    else exitText.setFillColor(sf::Color(255, 255, 255, 255));

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            Game::setInGame(true);
        }
        if(exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) window.close();
    }
}

void MainMenu::draw(Renderer& renderer)
{
    sf::Texture test;
    test.loadFromFile("assets/background2.png");
    background.setTexture(test);
    renderer.target.draw(background);
    //renderer.target.draw(title);
    renderer.target.draw(startButton);
    renderer.target.draw(startText);
    renderer.target.draw(exitButton);
    //renderer.target.draw(exitText);
}