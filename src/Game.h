//
// Created by nylux on 07.03.2024.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include <SFML/Graphics.hpp>
#include "engine/Camera.h"
#include "engine/Renderer.h"
#include "entities/Object.h"
#include "entities/Player.h"
#include "scenes/PauseMenu.h"
#include "scenes/MainMenu.h"
#include "scenes/DeathMenu.h"

class Game
{
public:
    static Game &getInstance();
    static void restart();
    static void init();
    void update(float deltaTime);
    void render(Renderer& renderer);
    void renderUI(Renderer& renderer, sf::RenderWindow& window);
    static void deleteObject(Object* object);

    Camera getCamera();

    static bool isPaused();
    static void setPaused(bool state);
    static bool isInGame();
    static void setInGame(bool state);
    static Player getPlayer();

private:
    Camera camera = Camera(20.0f);
    MainMenu mainMenu = MainMenu();
    PauseMenu pauseMenu = PauseMenu();
    static bool paused;
    static bool inGame;
    static Player player;
};


#endif //CMAKESFMLPROJECT_GAME_H
