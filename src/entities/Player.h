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

    void OnBeginContact(b2Fixture* other) override;
    void OnEndContact(b2Fixture* other) override;

    sf::Vector2f position{};
    float angle{};

    size_t health = 2;
private:
    FixtureData fixture_data{};

    Animation runAnimation;
    Animation idleAnimation;
    Animation jumpAnimation;
    sf::Texture textureToDraw;

    b2Body* body{};
    size_t onGround = 0;
    bool rotation = false;
};



#endif //PLAYER_H
