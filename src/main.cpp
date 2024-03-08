#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Game.cpp"
#include "Renderer.h"


int main()
{
    auto window = sf::RenderWindow{ sf::VideoMode(1200, 900), "CMake SFML Project" };
    sf::Clock deltaClock;
    window.setFramerateLimit(144);

    Camera camera;
    Renderer renderer(window);

    begin(window);
    while (window.isOpen())
    {
        float deltaTime = deltaClock.restart().asSeconds();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.setView(camera.getView(window.getSize()));
        update(deltaTime);

        window.clear(sf::Color(20, 20, 20));

        render(renderer);

        window.display();
    }
}
