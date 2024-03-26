//
// Created by nylux on 25.03.2024.
//

#include "Heart.h"
#include "../Resources.h"
#include "../engine/FixtureData.h"
#include "../engine/Physics.h"
#include "Box2D/b2_fixture.h"
#include "Box2D/b2_polygon_shape.h"

Heart::~Heart()
{
    Physics::world.DestroyBody(body);
}


void Heart::begin()
{
    tag = "heart";
    animation = Animation(0.6f,
{
            AnimationFrame(0.3f, Resources::textures["heart_idle_00.png"]),
            AnimationFrame(0.0f, Resources::textures["heart_idle_01.png"])
        });

    b2BodyDef bodyDef{};
    bodyDef.position.Set(position.x, position.y);
    b2Body* body = Physics::world.CreateBody(&bodyDef);
    b2PolygonShape shape{};
    shape.SetAsBox(0.4f, 0.4f);

    FixtureData* fixture_data = new FixtureData();
    fixture_data->type = FixtureDataType::Object;
    fixture_data->object = this;

    b2FixtureDef fixtureDef{};
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(fixture_data);
    fixtureDef.isSensor = true;
    fixtureDef.density = 0.0f;
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
}

void Heart::update(const float deltaTime)
{
    animation.update(deltaTime);
}

void Heart::render(Renderer &renderer)
{
    renderer.draw(animation.getTexture(), position, sf::Vector2f(1.0f, 1.0f));
}
