//
// Created by nylux on 21.03.2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../engine/Renderer.h"
#include "box2d/b2_body.h"
#include "SFML/System/Vector2.hpp"


class Player
{
public:
    void begin();
    void update(float deltaTime);
    void draw(Renderer& renderer) const;

    sf::Vector2f position{};
    float angle{};

private:
    b2Body* body{};
};



#endif //PLAYER_H
