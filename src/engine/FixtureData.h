//
// Created by nylux on 26.03.2024.
//

#ifndef FIXTUREDATA_H
#define FIXTUREDATA_H
#include "Collision.h"

class Player;
class Object;

enum class FixtureDataType
{
    Player,
    MapTile,
    Object
};

struct FixtureData
{
    Collision* listener;
    FixtureDataType type;

    union
    {
        [[maybe_unused]] Player* player;
        Object* object;
        struct
        {
            [[maybe_unused]] int mapX;
            [[maybe_unused]] int mapY;
        };
    };
};

#endif //FIXTUREDATA_H
