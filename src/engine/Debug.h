//
// Created by nylux on 23.03.2024.
//

#ifndef DEBUG_H
#define DEBUG_H
#include "box2d/b2_draw.h"
#include "SFML/Graphics/RenderTarget.hpp"
/**
 * @brief Class that handles the debug drawing (the shapes that show the physics bodies)
 */
class Debug final : public b2Draw
{
public:
    explicit Debug(sf::RenderTarget& target) : target(target)
    {
    }

    void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

    void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

    void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) override;

    void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) override;

    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;

    void DrawTransform(const b2Transform &xf) override;

    void DrawPoint(const b2Vec2 &p, float size, const b2Color &color) override;

private:
    sf::RenderTarget& target;
};



#endif //DEBUG_H
