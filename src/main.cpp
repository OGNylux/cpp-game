#include <SFML/Graphics.hpp>

#include "engine/Camera.h"
#include "Game.cpp"
#include "engine/Renderer.h"
#include "scenes/PauseMenu.h"

Game game;

int main()
{
    auto window = sf::RenderWindow{ sf::VideoMode(1200, 900), "CMake SFML Project" };
    sf::Clock deltaClock;
    Renderer renderer(window);

    window.setFramerateLimit(60);
    game.init();
    while (window.isOpen())
    {
        float deltaTime = deltaClock.restart().asSeconds();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) game.setPaused(!game.isPaused());
        }
        game.update(deltaTime);

        window.clear();
        window.setView(game.getCamera().getView(window.getSize()));
        game.render(renderer);

        window.setView(game.getCamera().getUIView(window.getSize()));
        game.renderUI(renderer, window);

        window.display();
    }
}
