//
// Created by nylux on 09.04.2024.
//

#ifndef PLATFORMER_DEATHMENU_H
#define PLATFORMER_DEATHMENU_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "../engine/Renderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class DeathMenu {
public:
    DeathMenu();

    void handleInput(sf::RenderWindow &window);

    void update(float delteTime);

    void draw(Renderer& renderer) const;

private:
    sf::RectangleShape background;

    sf::Text title;

    sf::RectangleShape startButton;
    sf::Text startText;

    sf::RectangleShape exitButton;
    sf::Text exitText;

    sf::Font font;
};


#endif //PLATFORMER_DEATHMENU_H
