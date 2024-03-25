//
// Created by nylux on 21.03.2024.
//

#ifndef MAP_H
#define MAP_H

#include <vector>

#include "entities/Object.h"
#include "engine/Renderer.h"
#include "SFML/Graphics/Image.hpp"

class Map
{
public:
    explicit Map(float cellSize = 32.0f);
    void createCheckerboard(size_t width, size_t height);
    sf::Vector2f createFromImage(const sf::Image&, std::vector<Object*>& objects);
    void draw(Renderer& renderer);

    std::vector<std::vector<int>> grid;
    float cellSize{};
};



#endif //MAP_H
