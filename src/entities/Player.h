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
    sf::Vector2f setPosition(sf::Vector2f newPosition);
    float getAngle() const;
    bool getDeadState() const;
    bool setDeadState(bool state);
private:
    FixtureData fixtureData{};

    Animation runAnimation;
    Animation idleAnimation;
    Animation jumpAnimation;
    sf::Texture textureToDraw;

    int health = 2;
    sf::Vector2f position;
    float angle{};
    bool isDead = false;

    b2Body* body{};
    b2Fixture* feet{};
    int onGround{};
    bool rotation = false;
};



#endif //PLAYER_H
