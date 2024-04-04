//
// Created by a3445 on 27.03.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "Object.h"
#include "../engine/Animation.h"
#include "../engine/FixtureData.h"
#include "box2d/b2_body.h"


class Renderer;

class Enemy final : public Object
{
public:
    void init() override;
    void update(float deltaTime) override;
    void render(Renderer& renderer) override;
    void checkPlayerDistance();
    bool getDeadState() const;

    void die();
private:
    float movementSpeed = 5.0f;

    float destroyTimer = 0.0f;
    float randomMoveTimer = 0.0f;
    bool isDead = false;
    bool playerInRange = false;
    bool arrivedAtDestination = false;

    Animation moveAnimation;
    Animation deathAnimation;
    sf::Texture textureToDraw;
    FixtureData fixtureData{};
    b2Body* body{};
};



#endif //ENEMY_H
