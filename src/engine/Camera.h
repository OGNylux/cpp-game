//
// Created by nylux on 08.03.2024.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "SFML/Graphics/View.hpp"
/**
 * @brief Class that handles the camera
 */
class Camera
{
public:
    explicit Camera(float zoomLevel = 5.0f);
    [[nodiscard]] sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f newPosition);
    sf::View getView(sf::Vector2u windowSize);
    sf::View getUIView(sf::Vector2u windowSize);
private:
    float zoomLevel;
    sf::Vector2f position;
    sf::Vector2f viewSize;
};



#endif //CAMERA_H
