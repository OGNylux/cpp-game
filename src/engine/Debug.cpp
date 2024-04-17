//
// Created by nylux on 23.03.2024.
//

#include "Debug.h"

#include <cmath>

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"

void Debug::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon(vertexCount);
    for (int i = 0; i < vertexCount; i++)
    {
        polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
    }
    polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineThickness(0.02f);
    polygon.setOutlineColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                      static_cast<sf::Uint8>(std::round(color.g * 255)),
                                      static_cast<sf::Uint8>(std::round(color.b * 255)),
                                      static_cast<sf::Uint8>(std::round(color.a * 255))));
    target.draw(polygon);
}

void Debug::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    sf::ConvexShape polygon(vertexCount);
    for (int i = 0; i < vertexCount; i++)
    {
        polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
    }
    polygon.setFillColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                   static_cast<sf::Uint8>(std::round(color.g * 255)),
                                   static_cast<sf::Uint8>(std::round(color.b * 255)),
                                   static_cast<sf::Uint8>(std::round(color.a * 255))));
    target.draw(polygon);
}


void Debug::DrawCircle(const b2Vec2 &center, float radius, const b2Color &color)
{
    sf::CircleShape circle(radius);
    circle.setPosition(center.x, center.y);
    circle.setOrigin(radius, radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(0.02f);
    circle.setOutlineColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                     static_cast<sf::Uint8>(std::round(color.g * 255)),
                                     static_cast<sf::Uint8>(std::round(color.b * 255)),
                                     static_cast<sf::Uint8>(std::round(color.a * 255))));
    target.draw(circle);
}

void Debug::DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color)
{
    sf::CircleShape circle(radius);
    circle.setPosition(center.x, center.y);
    circle.setOrigin(radius, radius);
    circle.setFillColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                  static_cast<sf::Uint8>(std::round(color.g * 255)),
                                  static_cast<sf::Uint8>(std::round(color.b * 255)),
                                  static_cast<sf::Uint8>(std::round(color.a * 255))));
    target.draw(circle);

    b2Vec2 p = center + (radius * axis);
    DrawSegment(center, p, color);
}

void Debug::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{
    sf::VertexArray line(sf::Lines, 2);
    sf::Color sfColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                static_cast<sf::Uint8>(std::round(color.g * 255)),
                                static_cast<sf::Uint8>(std::round(color.b * 255)),
                                static_cast<sf::Uint8>(std::round(color.a * 255))));
    line[0].position = sf::Vector2f(p1.x, p1.y);
    line[0].color = sfColor;
    line[1].position = sf::Vector2f(p2.x, p2.y);
    line[1].color = sfColor;
    target.draw(line);
}

void Debug::DrawTransform(const b2Transform &xf)
{
    const b2Vec2 p = xf.p;
    const b2Vec2 px = p + (0.5f * xf.q.GetXAxis());
    const b2Vec2 py = p + (0.5f * xf.q.GetYAxis());

    DrawSegment(p, px, b2Color(1.0f, 0.0f, 0.0f));
    DrawSegment(p, py, b2Color(1.0f, 0.0f, 0.0f));
}

void Debug::DrawPoint(const b2Vec2 &p, float size, const b2Color &color)
{
    sf::CircleShape circle(size);
    circle.setPosition(p.x, p.y);
    circle.setOrigin(size, size);
    circle.setFillColor(sf::Color(static_cast<sf::Uint8>(std::round(color.r * 255.0f)),
                                  static_cast<sf::Uint8>(std::round(color.g * 255)),
                                  static_cast<sf::Uint8>(std::round(color.b * 255)),
                                  static_cast<sf::Uint8>(std::round(color.a * 255))));
    target.draw(circle);
}
