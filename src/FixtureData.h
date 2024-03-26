//
// Created by nylux on 26.03.2024.
//

#ifndef FIXTUREDATA_H
#define FIXTUREDATA_H
#include "engine/Collision.h"

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
        Player* player;
        Object* object;
        struct
        {
            int mapX;
            int mapY;
        };
    };
};

#endif //FIXTUREDATA_H
