//
// Created by nylux on 21.03.2024.
//

#include <filesystem>
#include "Resources.h"

std::unordered_map<std::string, sf::Texture> Resources::textures{};

void Resources::initTexture(const std::string& path)
{
    for (auto& file : std::filesystem::directory_iterator(path))
    {
        if (file.is_regular_file() && (file.path().extension() == ".png" || file.path().extension() == ".jpg"))
        {
            Resources::textures[file.path().filename().string()].loadFromFile(file.path().string());
        }
    }
}