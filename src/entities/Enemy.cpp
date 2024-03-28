//
// Created by a3445 on 27.03.2024.
//

#include "Enemy.h"

#include "../Game.h"
#include "../Resources.h"
#include "../engine/FixtureData.h"
#include "../engine/Physics.h"
#include "box2d/b2_circle_shape.h"
#include "Box2D/b2_fixture.h"

void Enemy::init()
{
    tag = "enemy";
    animation = Animation(0.6f,
{
            AnimationFrame(0.3f, Resources::textures["block2.png"]),
            AnimationFrame(0.0f, Resources::textures["block.png"])
        });

    b2BodyDef bodyDef{};
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = Physics::world->CreateBody(&bodyDef);

    fixtureData.type = FixtureDataType::Object;
    fixtureData.object = this;

    b2CircleShape circle_shape;
    circle_shape.m_radius = 0.5f;

    b2FixtureDef fixtureDef{};
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(&fixtureData);
    fixtureDef.shape = &circle_shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    body->CreateFixture(&fixtureDef);

}

void Enemy::update(const float deltaTime)
{
    if(isDead)
    {
        destroyTimer += deltaTime;
        if(destroyTimer >= 2.0f) deleteObject(this);
        return;
    }

    animation.update(deltaTime);

    b2Vec2 velocity = body->GetLinearVelocity();

    if(velocity.x == 0.0f)
    {
        movementSpeed = -movementSpeed;
    }

    velocity.x = movementSpeed;

    body->SetLinearVelocity(velocity);

    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
    angle = body->GetAngle() * (180.0f / std::numbers::pi);
}

void Enemy::render(Renderer& renderer)
{
    renderer.draw(animation.getTexture(), !isDead ? position : sf::Vector2f(position.x, position.y + 0.45f), sf::Vector2f(1.0f, isDead ? 0.5f : 1.0f), angle);
}

bool Enemy::getDeadState() const
{
    return isDead;
}

void Enemy::die()
{
    isDead = true;
    Physics::bodiesToDestroy.push_back(body);
}
