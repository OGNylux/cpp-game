//
// Created by nylux on 16.04.2024.
//

#include <stdexcept>
#include "TextureManager.h"

TextureManager &TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

void TextureManager::loadTexture(const std::string &path) {
    if (this->textures.find(path) != this->textures.end()) return;
    sf::Texture texture;
    if (!texture.loadFromFile(path)) throw std::runtime_error("Error loading texture: " + path + ".");

    this->textures[path] = texture;
}

sf::Texture &TextureManager::getTexture(const std::string &path) {
    const auto texture = this->textures.find(path);
    if (texture == this->textures.end()) throw std::runtime_error("TextureManager::getTexture - Texture " + path + " not found. Maybe you forgot to load it?");
    return texture->second;
}