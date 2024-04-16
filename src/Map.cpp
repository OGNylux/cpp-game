//
// Created by nylux on 21.03.2024.
//

#include <map>
#include <iostream>
#include "Map.h"

#include "engine/FixtureData.h"
#include "engine/Physics.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "entities/Enemy.h"
#include "entities/Heart.h"
#include "entities/Object.h"
#include "entities/Decor.h"

struct ColorComparator {
    bool operator() (const sf::Color& a, const sf::Color& b) const {
        if (a.r != b.r)
            return a.r < b.r;
        if (a.g != b.g)
            return a.g < b.g;
        return a.b < b.b;
    }
};

std::map<sf::Color, std::string, ColorComparator> colorToTexture = {
        {sf::Color(10, 0, 0), "assets/blocks/grass_00.png"},
        {sf::Color(20, 0, 0), "assets/blocks/grass_01.png"},
        {sf::Color(30, 0, 0), "assets/blocks/grass_02.png"},
        {sf::Color(40, 0, 0), "assets/blocks/grass_03.png"},
        {sf::Color(50, 0, 0), "assets/blocks/grass_04.png"},
        {sf::Color(60, 0, 0), "assets/blocks/grass_05.png"},
        {sf::Color(70, 0, 0), "assets/blocks/grass_06.png"},
        {sf::Color(80, 0, 0), "assets/blocks/grass_07.png"},
        {sf::Color(90, 0, 0), "assets/blocks/grass_08.png"},
        {sf::Color(100, 0, 0), "assets/blocks/grass_09.png"},
        {sf::Color(110, 0, 0), "assets/blocks/grass_10.png"},
        {sf::Color(120, 0, 0), "assets/blocks/grass_11.png"},
        {sf::Color(130, 0, 0), "assets/blocks/grass_12.png"},
        {sf::Color(140, 0, 0), "assets/blocks/grass_13.png"},
        {sf::Color(150, 0, 0), "assets/blocks/grass_14.png"},
        {sf::Color(160, 0, 0), "assets/blocks/grass_15.png"},
        {sf::Color(170, 0, 0), "assets/blocks/grass_16.png"},
        {sf::Color(180, 0, 0), "assets/blocks/platform_00.png"},
        {sf::Color(190, 0, 0), "assets/blocks/platform_01.png"},
        {sf::Color(200, 0, 0), "assets/blocks/platform_02.png"},
        {sf::Color(210, 0, 0), "assets/blocks/platform_03.png"},
        {sf::Color(220, 0, 0), "assets/blocks/platform_04.png"}
};

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
            for (const auto& pair : colorToTexture)
            {
                if (color == pair.first)
                {
                    TextureManager::getInstance().loadTexture(pair.second);
                    grid[x][y] = &TextureManager::getInstance().getTexture(pair.second);
                    break;
                }
            }
            if(color == sf::Color::Yellow) object = new Heart();
            else if(color == sf::Color::Green) object = new Enemy();
            else if(color == sf::Color(0,250,0)) object = new Decor("assets/decor/tree.png", {0, -4}, {7, 9});
            else if(color == sf::Color(0, 240, 0)) object = new Decor("assets/decor/small_tree.png", {0, -1.5}, {4, 4});
            else if(color == sf::Color(0, 230, 0)) object = new Decor("assets/decor/stone.png", {0, -0.5}, {2, 2});
            else if(color == sf::Color(0, 220, 0)) object = new Decor("assets/decor/small_stone.png", {0, 0}, {1, 1});
            else if(color == sf::Color(0, 210, 0)) object = new Decor("assets/decor/bush.png", {0, -0.5}, {4, 2});
            else if(color == sf::Color(0, 200, 0)) object = new Decor("assets/decor/small_bush.png", {0, -0.5}, {3, 2});
            else if(color == sf::Color(0, 190, 0))
            {
                // generate a random number between 0 and 3
                int random = rand() % 4;
                std::string test = "assets/decor/flower_0" + std::to_string(random) + ".png";
                object = new Decor(test, {0, 0}, {1, 1});
            }
            else if(color == sf::Color(0, 180, 0))
            {
                // generate a random number between 0 and 2
                int random = rand() % 3;
                std::string test = "assets/decor/grass_foliage_0" + std::to_string(random) + ".png";
                object = new Decor(test, {0, 0}, {1, 1});
            }

            if(object)
            {
                object -> position = getCenterOfCell(x, y);
                if(std::string(typeid(*object).name()) == "5Decor" || std::string(typeid(*object).name()) == "class Decor") objects.insert(objects.begin(), object);
                else objects.push_back(object);
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
