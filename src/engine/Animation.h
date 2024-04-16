//
// Created by nylux on 24.03.2024.
//

#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include "SFML/Graphics/Texture.hpp"
#include "../TextureManager.h"

struct AnimationFrame
{
    explicit AnimationFrame(float time = 0.0f, std::string path = "") : time(time)
    {
        TextureManager::getInstance().loadTexture(path);
        texture = &TextureManager::getInstance().getTexture(path);
    }

    float time = 0.0f;
    sf::Texture* texture;
};

class Animation
{
public:
    explicit Animation(float length = 0.0f, std::vector<AnimationFrame> frames = {}, bool holdOnLastFrame = false);
    void update(float deltaTime);
    sf::Texture * getTexture();
    void reset();

private:
    float time = 0.0f;
    float length;
    bool holdOnLastFrame = false;
    std::vector<AnimationFrame> frames;
};

#endif //ANIMATIONS_H