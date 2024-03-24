//
// Created by nylux on 24.03.2024.
//

#include "Animation.h"

#include <utility>

Animation::Animation(float length, std::vector<AnimationFrame> frames, const bool holdOnLastFrame) : length(length), holdOnLastFrame(holdOnLastFrame), frames(std::move(frames))
{
}

void Animation::update(float deltaTime)
{
    if (!holdOnLastFrame || time <= length) {
        time += deltaTime;
    }
}

sf::Texture Animation::getTexture() {
    if (holdOnLastFrame && time > length) {
        return frames.back().texture;
    }

    while(time > length) time -= length;
    for (auto& frame: frames)
    {
        if(time >= frame.time) return frame.texture;
    }
    return frames.back().texture;
}

void Animation::reset() {
    time = 0.0f;
}

