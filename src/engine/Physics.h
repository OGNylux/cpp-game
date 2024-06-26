//
// Created by nylux on 21.03.2024.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <box2d/b2_world.h>

#include "Debug.h"
#include "Renderer.h"
/**
 * @brief Class that handles physics
 * @details This class initializes the physics world and updates it
 */
class Physics
{
public:
    static void init();
    static void update(float deltaTime);

    [[maybe_unused]] static void debugDraw(const Renderer& renderer);
    static std::vector<b2Body*> bodiesToDestroy;
    static b2World* world;
    static Debug* debug;
};



#endif //PHYSICS_H
