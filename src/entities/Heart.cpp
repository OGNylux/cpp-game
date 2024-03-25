//
// Created by nylux on 25.03.2024.
//

#include "Heart.h"
#include "../Resources.h"

void Heart::begin()
{
    animation = Animation(0.6f,
{
            AnimationFrame(0.3f, Resources::textures["heart_idle_00.png"]),
            AnimationFrame(0.0f, Resources::textures["heart_idle_01.png"])
        });

}

void Heart::update(const float deltaTime)
{
    animation.update(deltaTime);
}

void Heart::render(Renderer &renderer)
{
    renderer.draw(animation.getTexture(), position, sf::Vector2f(1.0f, 1.0f));
}
