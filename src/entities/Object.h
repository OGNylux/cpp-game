//
// Created by nylux on 25.03.2024.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <string>

#include "../engine/Renderer.h"

/**
 * @brief Class that handles the objects
 * @details This class is a base class for all objects
 */
class Object
{
public:
    virtual ~Object() = default;
    virtual void init() {}
    virtual void update(float deltaTime) {}
    virtual void render(Renderer& renderer) {}
    virtual void initAnimations() {};
    virtual void initCollisionBoxes() {};
    [[nodiscard]] virtual bool getCollected() const { return false; }
    virtual void setCollected(bool state) {};

    std::string tag;

    sf::Vector2f position;
    sf::Vector2f positionCorrection;
    float angle;
};

#endif //OBJECT_H
