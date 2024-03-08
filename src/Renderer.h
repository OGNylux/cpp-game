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
    Renderer(sf::RenderTarget& target);

    void draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size);

private:
    sf::Sprite sprite{};
    sf::RenderTarget& target;
};



#endif //RENDERER_H
