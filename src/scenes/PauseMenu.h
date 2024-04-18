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

/**
 * @brief Class that handles the pause menu
 */
class PauseMenu {
public:
    PauseMenu();

    void handleInput(sf::RenderWindow &window);
    void draw(Renderer& renderer);

private:
    sf::RectangleShape background;

    sf::Text title;

    sf::RectangleShape startButton;
    sf::Text startText;

    sf::RectangleShape exitButton;
    sf::Text exitText;
};


#endif //PLATFORMER_PAUSEMENU_H
