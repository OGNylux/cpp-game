//
// Created by nylux on 07.03.2024.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include <SFML/Graphics.hpp>
#include "engine/Camera.h"
#include "engine/Renderer.h"
#include "entities/Object.h"

extern Camera camera;
extern bool paused;

void restart();
void init(const sf::Window& window);
void initTextures(const std::string& path);
void update(float deltaTime);
void render(Renderer& renderer);
void renderUI(Renderer& renderer, const sf::Window& window);

void deleteObject(Object* object);

#endif //CMAKESFMLPROJECT_GAME_H
