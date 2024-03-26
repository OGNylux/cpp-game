//
// Created by nylux on 08.03.2024.
//

#include "Renderer.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

Renderer::Renderer(sf::RenderTarget &target) : target(target)
{
}


void Renderer::draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, float angle)
{
    sprite.setTexture(texture, true);
    sprite.setOrigin(static_cast<sf::Vector2f>(texture.getSize()) / 2.0f);
    sprite.setRotation(angle);
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(size.x / texture.getSize().x, size.y / texture.getSize().y));
    target.draw(sprite);
}
void Renderer::draw2(const sf::Texture& texture, const sf::Vector2f& position, float angle)
{
    sprite.setTexture(texture);
    sprite.setRotation(angle);
    sprite.setPosition(position);
    sprite.setTextureRect({0, 0, 100, static_cast<int>(texture.getSize().y)});
    target.draw(sprite);
}