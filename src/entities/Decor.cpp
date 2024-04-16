//
// Created by a3445 on 05.04.2024.
//

#include "Decor.h"

#include <utility>
#include "../TextureManager.h"

Decor::Decor(std::string path, sf::Vector2f positionCorrection, sf::Vector2f size) : path(std::move(path)), positionCorrection(positionCorrection), size(size)
{
}


void Decor::render(Renderer &renderer)
{
    sf::Vector2f newPosition = {position.x + positionCorrection.x, position.y + positionCorrection.y};
    TextureManager::getInstance().loadTexture(path);
    sf::Texture& texture = TextureManager::getInstance().getTexture(path);
    renderer.draw(texture, newPosition, size);
}
