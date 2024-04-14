//
// Created by nylux on 24.03.2024.
//

#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include "SFML/Graphics/Texture.hpp"

struct AnimationFrame
{
    explicit AnimationFrame(const float time = 0.0f, const sf::Texture* texture = nullptr) : time(time), texture(texture)
    {
    }

    float time = 0.0f;
    const sf::Texture* texture;
};

class Animation
{
public:
    explicit Animation(float length = 0.0f, std::vector<AnimationFrame> frames = {}, bool holdOnLastFrame = false);
    void update(float deltaTime);
    const sf::Texture* getTexture();
    void reset();

private:
    float time = 0.0f;
    float length;
    bool holdOnLastFrame = false;
    std::vector<AnimationFrame> frames;
};

#endif //ANIMATIONS_H