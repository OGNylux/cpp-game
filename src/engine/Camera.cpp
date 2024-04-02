//
// Created by nylux on 08.03.2024.
//

#include <iostream>
#include "Camera.h"

Camera::Camera(const float zoomLevel) : zoomLevel(zoomLevel)
{
}

float Camera::getZoomLevel() const
{
    return zoomLevel;
}

sf::Vector2f Camera::getPosition() const
{
    return position;
}

void Camera::setPosition(const sf::Vector2f newPosition)
{
    position = newPosition;
}

sf::Vector2f Camera::getViewSize() const
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

sf::View Camera::getUIView(const sf::Vector2u windowSize)
{
    float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    if(aspect < 1.0f) viewSize = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else viewSize = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    aspect = viewSize.x / viewSize.y;
    viewSize = sf::Vector2f(100.0f, 100.0f / aspect);
    return {sf::Vector2f(viewSize.x / 2.0f, viewSize.y / 2.0f), viewSize};
}
