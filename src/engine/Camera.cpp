//
// Created by nylux on 08.03.2024.
//

#include "Camera.h"

Camera::Camera(const float zoomLevel) : zoomLevel(zoomLevel)
{
}

sf::Vector2f Camera::getViewSize()
{
    return viewSize;
}

sf::View Camera::getView(const sf::Vector2u windowSize)
{
    const float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    if(aspect < 1.0f) viewSize = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else viewSize = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    return {position, viewSize};
}
