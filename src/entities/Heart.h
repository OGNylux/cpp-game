//
// Created by nylux on 25.03.2024.
//

#ifndef HEART_H
#define HEART_H
#include "Object.h"
#include "../engine/Animation.h"
#include <box2d/b2_body.h>

class Heart final : public Object
{
public:
    ~Heart() override;

    void init() override;
    void update(float deltaTime) override;
    void render(Renderer &renderer) override;
    [[nodiscard]] bool getCollected() const override;
    void setCollected(bool state) override;

private:
    bool isCollected = false;
    b2Body* body{};
    Animation animation;
};



#endif //HEART_H
