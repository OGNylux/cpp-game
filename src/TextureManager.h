//
// Created by nylux on 16.04.2024.
//

#ifndef PLATFORMER_TEXTUREMANAGER_H
#define PLATFORMER_TEXTUREMANAGER_H

#include <map>
#include <string>
#include "SFML/Graphics/Texture.hpp"

/**
 * @brief Class that handles the textures
 * @details This class is responsible for loading and storing textures
 */
class TextureManager {
public:
    static TextureManager &getInstance();

    void loadTexture(const std::string &path);

    sf::Texture &getTexture(const std::string &path);

private:
    std::map<std::string, sf::Texture> textures;
};


#endif //PLATFORMER_TEXTUREMANAGER_H
