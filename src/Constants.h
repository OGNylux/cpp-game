//
// Created by nylux on 18.04.2024.
//

#include "SFML/Graphics/Color.hpp"
#include "entities/Heart.h"
#include "entities/Enemy.h"
#include "entities/Decor.h"
#include <map>
#include <iostream>
#include <random>
#include <functional>

#ifndef PLATFORMER_CONSTANTS_H
#define PLATFORMER_CONSTANTS_H

#endif //PLATFORMER_CONSTANTS_H

struct ColorComparator {
    bool operator() (const sf::Color& a, const sf::Color& b) const {
        if (a.r != b.r)
            return a.r < b.r;
        if (a.g != b.g)
            return a.g < b.g;
        return a.b < b.b;
    }
};

std::map<sf::Color, std::string, ColorComparator> COLORTOTEXTURE = {
        {sf::Color(10, 0, 0), "assets/blocks/grass_00.png"},
        {sf::Color(20, 0, 0), "assets/blocks/grass_01.png"},
        {sf::Color(30, 0, 0), "assets/blocks/grass_02.png"},
        {sf::Color(40, 0, 0), "assets/blocks/grass_03.png"},
        {sf::Color(50, 0, 0), "assets/blocks/grass_04.png"},
        {sf::Color(60, 0, 0), "assets/blocks/grass_05.png"},
        {sf::Color(70, 0, 0), "assets/blocks/grass_06.png"},
        {sf::Color(80, 0, 0), "assets/blocks/grass_07.png"},
        {sf::Color(90, 0, 0), "assets/blocks/grass_08.png"},
        {sf::Color(100, 0, 0), "assets/blocks/grass_09.png"},
        {sf::Color(110, 0, 0), "assets/blocks/grass_10.png"},
        {sf::Color(120, 0, 0), "assets/blocks/grass_11.png"},
        {sf::Color(130, 0, 0), "assets/blocks/grass_12.png"},
        {sf::Color(140, 0, 0), "assets/blocks/grass_13.png"},
        {sf::Color(150, 0, 0), "assets/blocks/grass_14.png"},
        {sf::Color(160, 0, 0), "assets/blocks/grass_15.png"},
        {sf::Color(170, 0, 0), "assets/blocks/grass_16.png"},
        {sf::Color(180, 0, 0), "assets/blocks/platform_00.png"},
        {sf::Color(190, 0, 0), "assets/blocks/platform_01.png"},
        {sf::Color(200, 0, 0), "assets/blocks/platform_02.png"},
        {sf::Color(210, 0, 0), "assets/blocks/platform_03.png"},
        {sf::Color(220, 0, 0), "assets/blocks/platform_04.png"}
};

std::map<sf::Color, std::function<Object * ()>, ColorComparator> COLORTOOBJECT = {
        {sf::Color::Yellow, []() { return new Heart(); }},
        {sf::Color::Green, []() { return new Enemy(); }},
        {sf::Color(0,250,0), []() { return new Decor("assets/decor/tree.png", {0, -4}, {7, 9}); }},
        {sf::Color(0, 240, 0), []() { return new Decor("assets/decor/small_tree.png", {0, -1.5}, {4, 4}); }},
        {sf::Color(0, 230, 0), []() { return new Decor("assets/decor/stone.png", {0, -0.5}, {2, 2}); }},
        {sf::Color(0, 220, 0), []() { return new Decor("assets/decor/small_stone.png", {0, 0}, {1, 1}); }},
        {sf::Color(0, 210, 0), []() { return new Decor("assets/decor/bush.png", {0, -0.5}, {4, 2}); }},
        {sf::Color(0, 200, 0), []() { return new Decor("assets/decor/small_bush.png", {0, -0.5}, {3, 2}); }},
        {sf::Color(0, 190, 0), []() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, 3);
            int random = distrib(gen);
            std::string test = "assets/decor/flower_0" + std::to_string(random) + ".png";
            return new Decor(test, {0, 0}, {1, 1});
        }},
        {sf::Color(0, 180, 0), []() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, 2);
            int random = distrib(gen);
            std::string test = "assets/decor/grass_foliage_0" + std::to_string(random) + ".png";
            return new Decor(test, {0, 0}, {1, 1});
        }}
};