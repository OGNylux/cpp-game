//
// Created by nylux on 23.03.2024.
//

#ifndef COLLISION_H
#define COLLISION_H
#include "box2d/b2_world_callbacks.h"

class Collision : public b2ContactListener
{
public:
    virtual void OnBeginContact(b2Fixture* other);
    virtual void OnEndContact(b2Fixture* other);

    void BeginContact(b2Contact *contact) override;
    void EndContact(b2Contact *contact) override;
};



#endif //COLLISION_H
