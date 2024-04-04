//
// Created by nylux on 21.03.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../engine/FixtureData.h"
#include "../engine/Animation.h"
#include "../engine/Collision.h"
#include "../engine/Renderer.h"
#include "SFML/System/Vector2.hpp"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

class Player final : public Collision
{
public:
    void init();
    void update(float deltaTime);
    void draw(Renderer& renderer);
    void OnBeginContact(b2Fixture *self, b2Fixture *other) override;
    void OnEndContact(b2Fixture *self, b2Fixture *other) override;
    int getHealth() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f newPosition);
    float getAngle() const;
    bool getDeadState() const;
    void setDeadState(bool state);
private:
    void initAnimations();
    void initCollisionBoxes();
    void createSwordFixture();
    FixtureData fixtureData{};

    Animation runAnimation;
    Animation swordRunAnimation;
    Animation idleAnimation;
    Animation swordIdleAnimation;
    Animation jumpAnimation;
    Animation attackAnimation;
    sf::Texture textureToDraw;

    int health = 2;
    sf::Vector2f position;
    float angle{};
    bool isDead = false;
    bool isHit = false;
    bool swordDrawn = false;
    bool attacking = false;
    float invulnerbilityTimer = 0.0f;
    float attackTimer = 0.0f;

    b2Body* body{};
    b2Fixture* center{};
    b2Fixture* feet{};
    b2Fixture* sword{};

    int onGround{};
    bool rotation = false;
};



#endif //PLAYER_H
