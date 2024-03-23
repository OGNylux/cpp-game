//
// Created by nylux on 21.03.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../engine/Collision.h"
#include "../engine/Renderer.h"
#include "SFML/System/Vector2.hpp"


class Player : public Collision
{
public:
    void begin();
    void update(float deltaTime);
    void draw(Renderer& renderer) const;

    void OnBeginContact() override;
    void OnEndContact() override;

    sf::Vector2f position{};
    float angle{};

private:
    b2Body* body{};
    bool onGround = false;
};



#endif //PLAYER_H
