//
// Created by nylux on 07.03.2024.
//

#ifndef CMAKESFMLPROJECT_GAME_H
#define CMAKESFMLPROJECT_GAME_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "Renderer.h"

void begin(const sf::Window& window);
void update(float deltaTime);
void render(Renderer& renderer);

#endif //CMAKESFMLPROJECT_GAME_H
