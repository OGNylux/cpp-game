//
// Created by nylux on 26.03.2024.
//

#ifndef FIXTUREDATA_H
#define FIXTUREDATA_H
#include "Collision.h"

class Player;
class Object;
/**
 * @brief Enum that holds the type of the fixture data
 */
enum class FixtureDataType
{
    Player,
    MapTile,
    Object
};

/**
 * @brief Struct that holds the fixture data
 */
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
