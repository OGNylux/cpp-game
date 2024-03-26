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
#include "entities/Heart.h"
#include "entities/Object.h"

Map::Map(const float cellSize) : cellSize(cellSize), grid()
{
}

void Map::createCheckerboard(const size_t width, const size_t height)
{
    grid = std::vector(width,std::vector(height,0));

    int last = 0;
    for (auto& column: grid)
    {
        for (auto& cell: column)
        {
            last = cell = !last;
        }
        if (width % 2 == 0) last = !last;
    }
}

sf::Vector2f Map::createFromImage(const sf::Image& image, std::vector<Object*>& objects)
{
    objects.clear();
    grid.clear();
    grid = std::vector(image.getSize().x,std::vector(image.getSize().y,0));

    sf::Vector2f playerPosition{};

    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[x].size(); y++)
        {
            sf::Color color = image.getPixel(x, y);
            if (color == sf::Color::Black)
            {
                grid[x][y] = 1;
                b2BodyDef bodyDef{};
                bodyDef.position.Set(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
                b2Body* body = Physics::world.CreateBody(&bodyDef);
                b2PolygonShape shape{};
                shape.SetAsBox(cellSize / 2.0f, cellSize / 2.0f);

                FixtureData* fixture_data = new FixtureData();
                fixture_data->type = FixtureDataType::MapTile;
                fixture_data->mapX = x;
                fixture_data->mapY = y;

                b2FixtureDef fixtureDef{};
                fixtureDef.shape = &shape;
                fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(fixture_data);
                fixtureDef.density = 0.0f;
                body->CreateFixture(&fixtureDef);
            }
            else if (color == sf::Color::Red) playerPosition = sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
            else if(color == sf::Color::Yellow)
            {
                Object* heart = new Heart();
                heart -> position = sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
                objects.push_back(heart);
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
            if(cell) renderer.draw(Resources::textures["block.png"], sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f), sf::Vector2f(cellSize, cellSize));
            y++;
        }
        x++;
    }
}
