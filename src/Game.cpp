//
// Created by nylux on 07.03.2024.
//

#include "Game.h"
#include "Resources.h"
#include "Map.h"
#include "entities/Player.h"

#include "engine/Physics.h"
#include "scenes/MainMenu.h"
#include "scenes/PauseMenu.h"
#include "scenes/DeathMenu.h"

Player Game::player = Player();
bool Game::paused = false;
bool Game::inGame = false;
Map map(1.0f);
std::vector<Object*> objects{};
sf::Image image;
PauseMenu pauseMenu = PauseMenu();
MainMenu mainMenu = MainMenu();
DeathMenu deathMenu = DeathMenu();

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::restart()
{
    Physics::init();
    player = Player();
    player.setPosition(map.createFromImage(image, objects));

    player.setDeadState(false);
    paused = false;
    player.init();

    for (auto object: objects)
    {
        object->init();
    }
}

void Game::init()
{
    Resources::initTexture("assets");
    Resources::initTexture("assets/blocks");
    Resources::initTexture("assets/decor");
    Resources::initTexture("assets/animations/player");
    Resources::initTexture("assets/animations/enemy");
    Resources::initTexture("assets/animations/heart");
    image.loadFromFile("assets/level.png");

    Physics::init();
    restart();
}

void Game::update(float deltaTime)
{
    if(paused || player.getDeadState()) return;

    Physics::update(deltaTime);
    player.update(deltaTime);
    camera.setPosition(player.getPosition());
    for (auto object: objects)
    {
        object->update(deltaTime);
    }
}

void Game::render(Renderer& renderer)
{
    sf::Texture test = Resources::textures["background2.png"];
    float parallax = 0.1f*getCamera().getPosition().x;
    renderer.draw(test, {30+parallax,20}, {100,42});
    renderer.draw(test, {130+parallax,20}, {100,42});
    map.draw(renderer);

    for (auto object: objects)
    {
        object->render(renderer);
    }

    player.draw(renderer);

    //Physics::debugDraw(renderer);
}

void Game::renderUI(Renderer &renderer, sf::RenderWindow &window)
{
    if(!inGame)
    {
        mainMenu.handleInput(window);
        mainMenu.draw(renderer);
    }
    else
    {
        sf::Texture& heartTexture = Resources::textures["heart_idle_00.png"];
        sf::Vector2u textureSize = heartTexture.getSize();
        sf::Vector2f position = {2.0f, 2.0f};

        for (int i = 0; i < player.getHealth(); i++)
        {
            renderer.draw(heartTexture, position, {static_cast<float>(textureSize.x)/4.0f, static_cast<float>(textureSize.y)/4.0f});
            position.x += 4.0f;
        }

        if(paused)
        {
            pauseMenu.handleInput(window);
            pauseMenu.draw(renderer);
        }
        else if (player.getDeadState())
        {
            deathMenu.handleInput(window);
            deathMenu.draw(renderer);
        }
    }
}

void Game::deleteObject(Object *object)
{
    const auto& iterator = std::find(objects.begin(), objects.end(), object);
    if (iterator != objects.end())
    {
        delete *iterator;
        objects.erase(iterator);
    }
}

Camera Game::getCamera()
{
    return camera;
}

bool Game::isPaused()
{
    return paused;
}

void Game::setPaused(bool state)
{
    paused = state;
}

bool Game::isInGame() {
    return inGame;
}

void Game::setInGame(bool state)
{
    inGame = state;
}

Player Game::getPlayer()
{
    return player;
}