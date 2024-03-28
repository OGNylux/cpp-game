//
// Created by nylux on 21.03.2024.
//

#include "Map.h"

#include "engine/FixtureData.h"
#include "engine/Physics.h"
#include "Resources.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "entities/Enemy.h"
#include "entities/Heart.h"
#include "entities/Object.h"

Map::Map(const float cellSize) : cellSize(cellSize)
{
}

sf::Vector2f Map::getCenterOfCell(const size_t x, const size_t y) const
{
    return {cellSize * static_cast<float>(x) + cellSize / 2.0f, cellSize * static_cast<float>(y) + cellSize / 2.0f};
}

sf::Vector2f Map::createFromImage(const sf::Image& image, std::vector<Object*>& objects)
{
    objects.clear();
    grid.clear();
    grid = std::vector(image.getSize().x,std::vector(image.getSize().y, static_cast<sf::Texture*>(nullptr)));

    sf::Vector2f playerPosition{};

    for (int x = 0; x < grid.size(); x++)
    {
        for (int y = 0; y < grid[x].size(); y++)
        {
            sf::Color color = image.getPixel(x, y);
            Object* object = nullptr;
            if (color == sf::Color::Red) playerPosition = getCenterOfCell(x, y);
            if (color == sf::Color::Black) grid[x][y] = &Resources::textures["block.png"];
            else if (color == sf::Color::Blue) grid[x][y] = &Resources::textures["block2.png"];
            else if(color == sf::Color::Yellow) object = new Heart();
            else if(color == sf::Color::Green) object = new Enemy();

            if(object)
            {
                object -> position = getCenterOfCell(x, y);
                objects.push_back(object);
            }
            else if(grid[x][y] != nullptr)
            {
                b2BodyDef bodyDef{};
                bodyDef.position.Set(getCenterOfCell(x, y).x, getCenterOfCell(x, y).y);
                b2Body* body = Physics::world->CreateBody(&bodyDef);
                b2PolygonShape shape{};
                shape.SetAsBox(cellSize / 2.0f, cellSize / 2.0f);

                auto* fixtureData = new FixtureData();
                fixtureData->type = FixtureDataType::MapTile;
                fixtureData->mapX = x;
                fixtureData->mapY = y;

                b2FixtureDef fixtureDef{};
                fixtureDef.shape = &shape;
                fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(fixtureData);
                fixtureDef.density = 0.0f;
                body->CreateFixture(&fixtureDef);
            }
        }
    }
    return playerPosition;
}

void Map::draw(Renderer& renderer)
{
    int x = 0;
    for (const auto& column: grid)
    {
        int y = 0;
        for (const auto& cell: column)
        {
            if(cell) renderer.draw(*cell, getCenterOfCell(x, y), sf::Vector2f(cellSize, cellSize));
            y++;
        }
        x++;
    }
}
