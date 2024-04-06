//
// Created by a3445 on 05.04.2024.
//

#include "Tree.h"
#include "../../Resources.h"

void Tree::init()
{
}

void Tree::update(float deltaTime)
{
}

void Tree::render(Renderer &renderer)
{
    renderer.draw(Resources::textures["tree.png"], {position.x, position.y-4.5f}, sf::Vector2f(10.0f, 10.0f));
}