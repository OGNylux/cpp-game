//
// Created by nylux on 08.03.2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

/**
 * @brief Class that handles rendering
 * @details This class is used to draw textures on the screen
 */
class Renderer
{
public:
    explicit Renderer(sf::RenderTarget& target);

    void draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, float angle = 0.0f);
    void drawDamage(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size, float angle = 0.0f);

    sf::RenderTarget& target;
private:
    sf::Sprite sprite;
    sf::Sprite damage;
};



#endif //RENDERER_H
