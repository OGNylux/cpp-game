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

constexpr float movementSpeed = 7.0f;
constexpr float jumpVelocity = 10.0f;

void Player::begin()
{
    b2BodyDef bodyDef{};
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.fixedRotation = true;
    body = Physics::world.CreateBody(&bodyDef);

    b2PolygonShape polygonShape{};
    polygonShape.SetAsBox(0.5f, 0.5f);
    b2FixtureDef fixtureDef{};
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    b2CircleShape circleShape{};
    circleShape.m_radius = 0.5f;
    circleShape.m_p.Set(0.0f, -0.5f);
    fixtureDef.shape = &circleShape;
    body->CreateFixture(&fixtureDef);

    circleShape.m_p.Set(0.0f, 0.5f);
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
    body->CreateFixture(&fixtureDef);
}

void Player::update(float deltaTime)
{
    float move = movementSpeed;

    b2Vec2 velocity = body->GetLinearVelocity();
    velocity.x = 0.0f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) move *= 2;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x += move;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) velocity.x -= move;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround) velocity.y = -jumpVelocity;
    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);

    body -> SetLinearVelocity(velocity);

    angle = body->GetAngle() * (180.0f / static_cast<float>(std::numbers::pi));
}

void Player::draw(Renderer& renderer) const {
    renderer.draw(Resources::textures["player.png"], position, sf::Vector2f(1.0f, 2.0f), angle);
}

void Player::OnBeginContact()
{
    std::cout << "OnGround" << std::endl;
    onGround = true;
}

void Player::OnEndContact()
{
    std::cout << "notGround" << std::endl;
    onGround = false;
}
