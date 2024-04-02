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

class Game
{
public:
    static Game & getInstance();
    void restart();
    void init();
    void update(float deltaTime);
    void render(Renderer& renderer);
    void renderUI(Renderer& renderer, sf::RenderWindow& window);
    static void deleteObject(Object* object);

    Camera getCamera() const;
    void setCamera(const Camera& camera);
    bool isPaused() const;
    static void setPaused(bool paused);
    static Player getPlayer();
    void setPlayer(const Player& player);

private:
    Camera camera = Camera(20.0f);
    static bool paused;
    static Player player;
};


#endif //CMAKESFMLPROJECT_GAME_H
