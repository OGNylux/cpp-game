//
// Created by nylux on 08.03.2024.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "SFML/Graphics/View.hpp"


class Camera
{
public:
    explicit Camera(float zoomLevel = 5.0f);
    sf::View getView(sf::Vector2u windowSize) const;

    float zoomLevel{};
    sf::Vector2f position{};
};



#endif //CAMERA_H
