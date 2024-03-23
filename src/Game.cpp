//
// Created by nylux on 07.03.2024.
//

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "entities/Player.h"
#include <filesystem>

#include "engine/Physics.h"

Map map(1.0f);
Camera camera(20.0f);
Player player;

void begin(const sf::Window& window)
{
    for (auto& file : std::filesystem::directory_iterator("assets"))
    {
        if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
        }
    }
    Physics::init();

    sf::Image image;
    image.loadFromFile("assets/level.png");
    player.position = map.createFromImage(image);
    player.begin();
}

void update(float deltaTime)
{
    Physics::update(deltaTime);
    player.update(deltaTime);
    camera.position = player.position;
}

void render(Renderer& renderer)
{
    map.draw(renderer);
    player.draw(renderer);

    Physics::debugDraw(renderer);
}