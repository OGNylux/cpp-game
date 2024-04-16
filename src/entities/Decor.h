//
// Created by a3445 on 05.04.2024.
//

#ifndef PLATFORMER_DECOR_H
#define PLATFORMER_DECOR_H


#include "Object.h"

class Decor : public Object {
public:
    explicit Decor(std::string resource, sf::Vector2f positionCorrection, sf::Vector2f size);
    void render(Renderer &renderer) override;

    std::string path;
    sf::Vector2f positionCorrection;
    sf::Vector2f size{};
};


#endif //PLATFORMER_DECOR_H
