//
// Created by nylux on 21.03.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../engine/Animation.h"
#include "../engine/Collision.h"
#include "../engine/Renderer.h"
#include "SFML/System/Vector2.hpp"


class Player : public Collision
{
public:
    void begin();
    void update(float deltaTime);
    void draw(Renderer& renderer);

    void OnBeginContact() override;
    void OnEndContact() override;

    sf::Vector2f position{};
    float angle{};

private:
    Animation runAnimation;
    Animation idleAnimation;
    Animation jumpAnimation;
    sf::Texture textureToDraw;

    b2Body* body{};
    size_t onGround = 0;
    bool rotation = false;
};



#endif //PLAYER_H
