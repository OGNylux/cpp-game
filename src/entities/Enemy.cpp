//
// Created by a3445 on 27.03.2024.
//

#include "Enemy.h"

#include "Player.h"
#include "../Game.h"
#include "../engine/Physics.h"
#include "box2d/b2_circle_shape.h"
#include <numbers>
#include <random>

float distanceTimer = 0.0f;

void Enemy::init()
{
    tag = "enemy";
    initAnimations();
    initCollisionBoxes();
}

void Enemy::update(const float deltaTime)
{
    moveAnimation.update(deltaTime);
    deathAnimation.update(deltaTime);

    textureToDraw = moveAnimation.getTexture();

    if(isDead)
    {
        destroyTimer += deltaTime;
        textureToDraw = deathAnimation.getTexture();
        if(destroyTimer >= 0.6f) Game::deleteObject(this);
        return;
    }

    b2Vec2 velocity = body->GetLinearVelocity();

    distanceTimer += deltaTime;
    if(distanceTimer >= 4.0f)  // Check distance every 4 seconds
    {
        checkPlayerDistance();
        distanceTimer = 0;
    }

    if(playerInRange)
    {
        if(Game::getPlayer().getPosition().x < position.x) movementSpeed = -5.0f;
        else movementSpeed = 5.0f;
    }
    else
    {
        randomMoveTimer += deltaTime;
        if(randomMoveTimer >= 1.5f)
        {
            randomMoveTimer = 0.0f;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(-5, 5);
            movementSpeed = static_cast<float>(distrib(gen));
        }
    }

    velocity.x = movementSpeed;

    body->SetLinearVelocity(velocity);

    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
    angle = body->GetAngle() * static_cast<float>(180.0f / std::numbers::pi);
}

void Enemy::render(Renderer& renderer)
{
    renderer.draw(*textureToDraw, sf::Vector2f(position.x, position.y - 0.4f), sf::Vector2f(2.0f, 2.0f), angle);
}

void Enemy::initAnimations()
{
    moveAnimation = Animation(0.6f,{
        AnimationFrame(0.45f, "assets/animations/enemy/slime_move_00.png"),
        AnimationFrame(0.30f, "assets/animations/enemy/slime_move_01.png"),
        AnimationFrame(0.15f, "assets/animations/enemy/slime_move_02.png"),
        AnimationFrame(0.0f, "assets/animations/enemy/slime_move_03.png")
    });

    deathAnimation = Animation(0.6f,{
        AnimationFrame(0.45f, "assets/animations/enemy/slime_death_00.png"),
        AnimationFrame(0.30f, "assets/animations/enemy/slime_death_01.png"),
        AnimationFrame(0.15f, "assets/animations/enemy/slime_death_02.png"),
        AnimationFrame(0.0f, "assets/animations/enemy/slime_death_03.png")
    });
}

void Enemy::initCollisionBoxes()
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = Physics::world->CreateBody(&bodyDef);

    fixtureData.type = FixtureDataType::Object;
    fixtureData.object = this;

    b2CircleShape circle_shape;
    circle_shape.m_radius = 0.5f;

    b2FixtureDef fixtureDef;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(&fixtureData);
    fixtureDef.shape = &circle_shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    body->CreateFixture(&fixtureDef);
}

void Enemy::checkPlayerDistance()
{
    float playerPosition = Game::getPlayer().getPosition().x;
    float deltaPosition = playerPosition - position.x;

    if(deltaPosition > 2.0f && deltaPosition < 10.0f)
    {
        playerInRange = true;
    }
    else
    {
        playerInRange = false;
    }
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
