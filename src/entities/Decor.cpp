//
// Created by a3445 on 05.04.2024.
//

#include "Decor.h"

#include <utility>
#include "../Resources.h"

Decor::Decor(std::string resource, sf::Vector2f positionCorrection, sf::Vector2f size)
{
    this->resource = std::move(resource);
    this->positionCorrection = positionCorrection;
    this->size = size;
}


void Decor::render(Renderer &renderer)
{
    sf::Vector2f newPosition = {position.x + positionCorrection.x, position.y + positionCorrection.y};
    renderer.draw(Resources::textures[resource], newPosition, size);
}
