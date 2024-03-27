//
// Created by nylux on 25.03.2024.
//

#ifndef HEART_H
#define HEART_H
#include "Object.h"
#include "../engine/Animation.h"
#include "Box2D/b2_body.h"


class Heart : public Object
{
public:
    ~Heart() override;

    void begin() override;
    void update(float deltaTime) override;
    void render(Renderer &renderer) override;
private:
    b2Body* body;
    Animation animation;
};



#endif //HEART_H
