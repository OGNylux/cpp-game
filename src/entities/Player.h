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
#include <Box2D/Box2D.h>

class Player : public Collision
{
public:
    void begin();
    void update(float deltaTime);
    void draw(Renderer& renderer);

    void OnBeginContact(b2Fixture *self, b2Fixture *other) override;
    void OnEndContact(b2Fixture *self, b2Fixture *other) override;
    size_t getHealth() const;

    sf::Vector2f position{};
    float angle{};
    bool isDead{};

private:
    FixtureData fixtureData{};

    Animation runAnimation;
    Animation idleAnimation;
    Animation jumpAnimation;
    sf::Texture textureToDraw;

    size_t health = 2;
    b2Body* body{};
    b2Fixture* feet{};
    size_t onGround{};
    bool rotation = false;
};



#endif //PLAYER_H
