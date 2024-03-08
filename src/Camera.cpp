//
// Created by nylux on 08.03.2024.
//

#include "Camera.h"

Camera::Camera(const float zoomLevel) : zoomLevel(zoomLevel)
{
}

sf::View Camera::getView(const sf::Vector2u windowSize) const
{
    const float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    sf::Vector2f size{};

    if(aspect < 1.0f) size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    return sf::View(sf::Vector2f(0.0f, 0.0f), size);
}
