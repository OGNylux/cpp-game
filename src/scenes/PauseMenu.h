//
// Created by a3445 on 02.04.2024.
//

#ifndef PLATFORMER_PAUSEMENU_H
#define PLATFORMER_PAUSEMENU_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "../engine/Renderer.h"

class PauseMenu {
public:
    PauseMenu();

    void handleInput(sf::RenderWindow &window);

    void update(float delteTime);

    void draw(Renderer& renderer) const;

private:
    sf::RectangleShape background;

    sf::RectangleShape startButton;
    sf::Text startText;

    sf::RectangleShape exitButton;
    sf::Text exitText;

    sf::Font font;
};


#endif //PLATFORMER_PAUSEMENU_H