#include <SFML/Graphics.hpp>

#include "engine/Camera.h"
#include "Game.cpp"
#include "engine/Renderer.h"


int main()
{
    auto window = sf::RenderWindow{ sf::VideoMode(1200, 900), "CMake SFML Project" };
    sf::Clock deltaClock;
    Renderer renderer(window);

    window.setFramerateLimit(60);
    init();
    while (window.isOpen())
    {
        float deltaTime = deltaClock.restart().asSeconds();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if(event.type == sf::Event::Closed)window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) paused = !paused;
        }
        update(deltaTime);

        window.clear();
        window.setView(camera.getView(window.getSize()));
        render(renderer);

        window.setView(camera.getUIView());
        renderUI(renderer);

        window.display();
    }
}
