//
// Created by nylux on 25.03.2024.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <string>

#include "../engine/Renderer.h"

class Object
{
public:
    virtual ~Object() = default;
    virtual void begin() {}
    virtual void update(float deltaTime) {}
    virtual void render(Renderer& renderer) {}

    std::string tag;

    sf::Vector2f position;
    float angle;
};

#endif //OBJECT_H
