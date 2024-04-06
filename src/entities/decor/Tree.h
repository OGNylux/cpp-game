//
// Created by a3445 on 05.04.2024.
//

#ifndef PLATFORMER_TREE_H
#define PLATFORMER_TREE_H

#include "../Object.h"

class Tree : public Object
        {
        public:
    void init() override;
    void update(float deltaTime) override;
    void render(Renderer &renderer) override;
};


#endif //PLATFORMER_TREE_H
