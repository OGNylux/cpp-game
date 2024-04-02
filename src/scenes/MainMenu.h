//
// Created by a3445 on 01.04.2024.
//

#ifndef PLATFORMER_MAINMENU_H
#define PLATFORMER_MAINMENU_H


#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"

class MainMenu {
public:
    MainMenu();

    void handleInput(sf::RenderWindow &window);

    void update(float delteTime);

    void draw(sf::RenderTarget &target) const;

private:
    sf::Sprite background;
    sf::Texture texture;

    sf::RectangleShape startButton;
    sf::Text startText;

    sf::RectangleShape exitButton;
    sf::Text exitText;

    sf::Font font;
};


#endif //PLATFORMER_MAINMENU_H
