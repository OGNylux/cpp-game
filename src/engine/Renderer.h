//
// Created by nylux on 08.03.2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"


class Renderer
{
public:
    explicit Renderer(sf::RenderTarget& target);

    void draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, float angle = 0.0f);
    void draw2(const sf::Texture& texture, const sf::Vector2f& position, float angle = 0.0f);

    sf::RenderTarget& target;
private:
    sf::Sprite sprite{};
    sf::Sprite sprite2{};
};



#endif //RENDERER_H
