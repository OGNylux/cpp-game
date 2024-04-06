//
// Created by a3445 on 05.04.2024.
//

#ifndef PLATFORMER_SMALLTREE_H
#define PLATFORMER_SMALLTREE_H

#include "../Object.h"

class SmallTree : public Object
        {
public:
    void init() override;
    void update(float deltaTime) override;
    void render(Renderer &renderer) override;
};

#endif //PLATFORMER_SMALLTREE_H
