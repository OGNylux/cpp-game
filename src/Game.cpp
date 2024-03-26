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
std::vector<Object*> objects;

void begin(const sf::Window& window)
{
    for (auto& file : std::filesystem::directory_iterator("assets"))
    {
        if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
        }
    }

    for (auto& file : std::filesystem::directory_iterator("assets/animations/player"))
    {
        if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
        }
    }
    Physics::init();

    sf::Image image;
    image.loadFromFile("assets/level.png");
    player.position = map.createFromImage(image, objects);
    player.begin();

    for (auto object: objects) {
        object -> begin();
    }
}

void update(float deltaTime)
{
    Physics::update(deltaTime);
    player.update(deltaTime);
    camera.position = player.position;
    for (auto object: objects) {
        object -> update(deltaTime);
    }
}

void render(Renderer& renderer)
{
    sf::Texture test = Resources::textures["background2.png"];
    renderer.draw(test, {30,10}, {100,42});
    renderer.draw(test, {130,10}, {100,42});

    map.draw(renderer);
    player.draw(renderer);

    for (auto object: objects) {
        object -> render(renderer);
    }

    Physics::debugDraw(renderer);
}

void deleteObject(Object* object)
{
    const auto& iterator = std::find(objects.begin(), objects.end(), object);
    if (iterator != objects.end())
    {
        delete *iterator;
        objects.erase(iterator);
    }
}