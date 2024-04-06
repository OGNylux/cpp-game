//
// Created by a3445 on 05.04.2024.
//

#include "SmallTree.h"
#include "../../Resources.h"

void SmallTree::init()
{
}

void SmallTree::update(float deltaTime)
{
}

void SmallTree::render(Renderer &renderer)
{
    renderer.draw(Resources::textures["smallTree.png"], {position.x, position.y-2.0f}, sf::Vector2f(7.5f, 7.5f));
}