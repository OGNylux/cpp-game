//
// Created by nylux on 21.03.2024.
//

#include "Player.h"

#include <iostream>

#include "../engine/Physics.h"
#include "../Resources.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_circle_shape.h"
#include "box2d/b2_polygon_shape.h"
#include "SFML/Window/Keyboard.hpp"
#include <numbers>

#include "Enemy.h"
#include "Object.h"
#include "../Game.h"

constexpr float movementSpeed = 7.0f;
constexpr float jumpVelocity = 10.0f;

void Player::begin()
{
    idleAnimation = Animation(1.0f,
{
           AnimationFrame(0.66f, Resources::textures["player_idle_02.png"]),
           AnimationFrame(0.33f, Resources::textures["player_idle_01.png"]),
           AnimationFrame(0.0f, Resources::textures["player_idle_00.png"]),
        });

    runAnimation = Animation(0.6f,
{
           AnimationFrame(0.5f, Resources::textures["player_run_05.png"]),
           AnimationFrame(0.4f, Resources::textures["player_run_04.png"]),
           AnimationFrame(0.3f, Resources::textures["player_run_03.png"]),
           AnimationFrame(0.2f, Resources::textures["player_run_02.png"]),
           AnimationFrame(0.1f, Resources::textures["player_run_01.png"]),
           AnimationFrame(0.0f, Resources::textures["player_run_00.png"])
        });

    jumpAnimation = Animation(0.4f,
{
           AnimationFrame(0.3f, Resources::textures["player_jump_03.png"]),
           AnimationFrame(0.2f, Resources::textures["player_jump_02.png"]),
           AnimationFrame(0.1f, Resources::textures["player_jump_01.png"]),
           AnimationFrame(0.0f, Resources::textures["player_jump_00.png"])
        }, true);

    fixtureData.listener = this;
    fixtureData.player = this;
    fixtureData.type = FixtureDataType::Player;

    b2BodyDef bodyDef{};
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = Physics::world.CreateBody(&bodyDef);

    b2FixtureDef fixtureDef{};
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(&fixtureData);
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;

    b2CircleShape circleShape{};
    circleShape.m_radius = 0.4f;
    circleShape.m_p.Set(0.0f, -0.5f);
    fixtureDef.shape = &circleShape;
    body->CreateFixture(&fixtureDef);

    circleShape.m_p.Set(0.0f, 0.5f);
    body->CreateFixture(&fixtureDef);


    b2PolygonShape polygonShape{};
    polygonShape.SetAsBox(0.5f, 0.25f);
    fixtureDef.shape = &polygonShape;
    body->CreateFixture(&fixtureDef);

    polygonShape.SetAsBox(0.4f, 0.2f, b2Vec2(0.0f, 1.0f), 0.0f);
    fixtureDef.isSensor = true;
    feet = body->CreateFixture(&fixtureDef);
}

void Player::update(float deltaTime)
{
    float move = movementSpeed;

    idleAnimation.update(deltaTime);
    runAnimation.update(deltaTime);
    jumpAnimation.update(deltaTime);

    b2Vec2 velocity = body->GetLinearVelocity();
    velocity.x = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) move *= 2;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x += move;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) velocity.x -= move;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround) velocity.y = -jumpVelocity;

    textureToDraw = runAnimation.getTexture();

    if(velocity.x < 0.0f) rotation = true;
    else if(velocity.x > 0.0f) rotation = false;
    else textureToDraw = idleAnimation.getTexture();

    if(!onGround) textureToDraw = jumpAnimation.getTexture();

    body -> SetLinearVelocity(velocity);
    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
    angle = body->GetAngle() * (180.0f / static_cast<float>(std::numbers::pi));
}

void Player::draw(Renderer& renderer) {
    renderer.draw(textureToDraw, {position.x, position.y-0.19f}, sf::Vector2f(rotation ? -(50.0f/16.0f) : (50.0f/16.0f), (37.0f/16.0f)), angle);
}

void Player::OnBeginContact(b2Fixture *self, b2Fixture* other)
{
    const auto* data = reinterpret_cast<FixtureData*>(other->GetUserData().pointer);

    if(!data) return;

    if(feet == self && data->type == FixtureDataType::MapTile)
    {
        onGround++;
        jumpAnimation.reset();
    }
    else if(data->type == FixtureDataType::Object && data->object->tag == "heart")
    {
        deleteObject(data->object);
        ++health;
        std::cout << "Health: " << health << std::endl;
    }
    else if(feet == self && data->type == FixtureDataType::Object && data->object->tag == "enemy")
    {
        auto* enemy = dynamic_cast<Enemy*>(data->object);
        if(enemy) enemy->die();
    }
}

void Player::OnEndContact(b2Fixture *self, b2Fixture* other)
{
    const auto* data = reinterpret_cast<FixtureData*>(other->GetUserData().pointer);

    if(!data) return;

    if(feet == self && data->type == FixtureDataType::MapTile && onGround > 0) onGround--;
}

size_t Player::getHealth() const {
    return health;
}
