//
// Created by nylux on 25.03.2024.
//

#include "Heart.h"

#include <iostream>

#include "../engine/FixtureData.h"
#include "../engine/Physics.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"

Heart::~Heart()
{
    Physics::bodiesToDestroy.push_back(body);
}

void Heart::init()
{
    tag = "heart";
    initAnimations();
    initCollisionBoxes();
}

void Heart::update(const float deltaTime)
{
    animation.update(deltaTime);
}

void Heart::render(Renderer &renderer)
{
    renderer.draw(*animation.getTexture(), position, sf::Vector2f(1.0f, 1.0f));
}

void Heart::initAnimations()
{
    animation = Animation(0.6f,{
        AnimationFrame(0.3f, "assets/animations/heart/heart_idle_00.png"),
        AnimationFrame(0.0f, "assets/animations/heart/heart_idle_01.png")
    });
}

void Heart::initCollisionBoxes()
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    body = Physics::world->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(0.4f, 0.4f);

    auto* fixture_data = new FixtureData();
    fixture_data->type = FixtureDataType::Object;
    fixture_data->object = this;

    b2FixtureDef fixtureDef;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(fixture_data);
    fixtureDef.isSensor = true;
    fixtureDef.density = 0.0f;
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
}

bool Heart::getCollected() const {
    return isCollected;
}

void Heart::setCollected(bool state) {
    isCollected = state;
}
