//
// Created by nylux on 07.03.2024.
//

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "entities/Player.h"
#include <filesystem>
#include <iostream>

#include "engine/Physics.h"

Map map(1.0f);
Camera camera(20.0f);
Player player;
std::vector<Object*> objects{};
sf::Image image;
bool paused{};

sf::RectangleShape background(sf::Vector2f(1.0f, 1.0f));

void restart()
{
    Physics::init();
    player = Player();
    player.position = map.createFromImage(image, objects);

    player.isDead = false;
    paused = false;
    player.init();


    for (auto object: objects)
    {
        object -> init();
    }
}

void init(const sf::Window& window)
{
    initTextures("assets");
    initTextures("assets/animations/player");
    initTextures("assets/animations/heart");
    image.loadFromFile("assets/level.png");

    background.setFillColor(sf::Color(0, 0, 0, 150));
    background.setOrigin(0.5f, 0.5f);

    Physics::init();
    restart();
}

void initTextures(const std::string& path)
{
    for (auto& file : std::filesystem::directory_iterator(path))
    {
        if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
        }
    }
}

void update(float deltaTime)
{
    if(player.isDead)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) restart();
        else paused = true;
    }
    if(paused) return;

    Physics::update(deltaTime);
    player.update(deltaTime);
    camera.position = player.position;
    for (auto object: objects)
    {
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

    for (auto object: objects)
    {
        object -> render(renderer);
    }

    Physics::debugDraw(renderer);
}

void renderUI(Renderer& renderer, sf::RenderWindow& window)
{
    sf::Texture& heartTexture = Resources::textures["heart_idle_00.png"];
    sf::Vector2u textureSize = heartTexture.getSize();
    sf::Vector2f position = -camera.getViewSize() / 2.0f + sf::Vector2f{2.0f, 2.0f};

    for (int i = 0; i < player.getHealth(); i++)
    {
        renderer.draw(heartTexture, position, {static_cast<float>(textureSize.x)/4.0f, static_cast<float>(textureSize.y)/4.0f});
        position.x += 4.0f;
    }

    if(paused)
    {
        background.setScale(camera.getViewSize());
        renderer.target.draw(background);
    }
}

void deleteObject(Object* object)
{
    const auto& iterator = std::ranges::find(objects, object);
    if (iterator != objects.end())
    {
        delete *iterator;
        std::cout << "Object deleted" << std::endl;
        objects.erase(iterator);
    }
}