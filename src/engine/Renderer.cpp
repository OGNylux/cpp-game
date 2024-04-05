//
// Created by nylux on 08.03.2024.
//

#include <iostream>
#include "Renderer.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "../Game.h"

Renderer::Renderer(sf::RenderTarget &target) : target(target)
{
}


void Renderer::draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, const float angle)
{
    sprite.setTexture(texture, true);
    sprite.setOrigin(static_cast<sf::Vector2f>(texture.getSize()) / 2.0f);
    sprite.setRotation(angle);
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(size.x / static_cast<float>(texture.getSize().x), size.y / static_cast<float>(texture.getSize().y)));
    target.draw(sprite);
}

void Renderer::drawDamage(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, const float angle)
{
    damage.setTexture(texture, true);
    damage.setOrigin(static_cast<sf::Vector2f>(texture.getSize()) / 2.0f);
    damage.setRotation(angle);
    damage.setPosition(position);
    damage.setColor(sf::Color::Red);
    damage.setScale(sf::Vector2f(size.x / static_cast<float>(texture.getSize().x), size.y / static_cast<float>(texture.getSize().y)));
    target.draw(damage);
}