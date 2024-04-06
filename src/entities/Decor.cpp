//
// Created by a3445 on 05.04.2024.
//

#include "Decor.h"
#include "../Resources.h"

Decor::Decor(std::string resource, sf::Vector2f positionCorrection, sf::Vector2f size)
{
    this->resource = resource;
    this->positionCorrection = positionCorrection;
    this->size = size;
}


void Decor::render(Renderer &renderer)
{
    renderer.draw(Resources::textures[resource], position, size);
}
