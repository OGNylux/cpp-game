//
// Created by nylux on 07.03.2024.
//

#include <SFML/Graphics.hpp>
#include "Game.h"

sf::Texture texture;

void begin(const sf::Window& window)
{
    if(!texture.loadFromFile("../src/block.png")) exit(-1);
}

void update(float deltaTime)
{
}

void render(Renderer& renderer)
{
    renderer.draw(texture, {0, 0}, {5, 5});
}