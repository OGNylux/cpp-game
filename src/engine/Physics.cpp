//
// Created by nylux on 21.03.2024.
//

#include "Physics.h"
#include "Collision.h"

b2World* Physics::world{};
Debug* Physics::debug = nullptr;
std::vector<b2Body*> Physics::bodiesToDestroy;

void Physics::init()
{
    delete world;

    world = new b2World(b2Vec2(0.0f, 9.8f));
    world -> SetDebugDraw(debug);

}

void Physics::update(const float deltaTime)
{
    world->Step(deltaTime, 8, 4);
    world->SetContactListener(new Collision());

    // this sucks but it works
    for (b2Body* body : bodiesToDestroy) {
        world->DestroyBody(body);
    }
    bodiesToDestroy.clear();
}

void Physics::debugDraw(Renderer& renderer)
{
    if (!debug)
    {
        debug = new Debug(renderer.target);
        debug->SetFlags(b2Draw::e_aabbBit);
        world->SetDebugDraw(debug);
    }

    world->DebugDraw();
}