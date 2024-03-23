//
// Created by nylux on 21.03.2024.
//

#include "Physics.h"

b2World Physics::world{b2Vec2(0.0f, 9.2f)};
Debug* Physics::debug = nullptr;

void Physics::init()
{

}

void Physics::update(float deltaTime)
{
    world.Step(deltaTime, 6, 2);
}

void Physics::debugDraw(Renderer& renderer)
{
    if (!debug)
    {
        debug = new Debug(renderer.target);
        debug->SetFlags(b2Draw::e_aabbBit);
        world.SetDebugDraw(debug);
    }

    world.DebugDraw();
}