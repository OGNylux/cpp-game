//
// Created by nylux on 21.03.2024.
//

#include "Player.h"

#include "../engine/Physics.h"
#include "../Resources.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "SFML/Window/Keyboard.hpp"
#include <numbers>

constexpr float movementSpeed = 70.0f;
constexpr float width = 1.0f;
constexpr float height = 2.0f;

void Player::begin()
{
    b2BodyDef bodyDef{};
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = Physics::world.CreateBody(&bodyDef);
    b2PolygonShape shape{};
    shape.SetAsBox(width / 2.0f, height / 2.0f);
    b2FixtureDef fixtureDef{};
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void Player::update(float deltaTime)
{
    float move = movementSpeed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) move *= 2;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) body -> ApplyForceToCenter(b2Vec2(move, 0.0f), true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) body -> ApplyForceToCenter(b2Vec2(-move, 0.0f), true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) body -> ApplyForceToCenter(b2Vec2(0.0f, -move), true);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) body -> ApplyForceToCenter(b2Vec2(0.0f, move), true);
    position = sf::Vector2f(body->GetPosition().x, body->GetPosition().y);
    angle = body->GetAngle() * (180.0f / static_cast<float>(std::numbers::pi));
}

void Player::draw(Renderer& renderer) const {
    renderer.draw(Resources::textures["player.png"], position, sf::Vector2f(width, height), angle);
}
