//
// Created by nylux on 21.03.2024.
//

#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>
#include <unordered_map>

#include "SFML/Graphics/Texture.hpp"

class Resources
{
public:
    static std::unordered_map<std::string, sf::Texture> textures;
    static void initTexture(const std::string& path);
};



#endif //RESOURCES_H
