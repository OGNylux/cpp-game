#include <SFML/Graphics.hpp>
#include <chrono>

#include "engine/Camera.h"
#include "Game.cpp"
#include "engine/Renderer.h"
#include "scenes/PauseMenu.h"

Game game;

int main()
{
    PauseMenu pauseMenu = PauseMenu();
    auto window = sf::RenderWindow{ sf::VideoMode(1200, 900), "CMake SFML Project", sf::Style::Close };
    sf::Clock deltaClock;
    Renderer renderer(window);

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    float fps;

    window.setFramerateLimit(60);
    game.init();
    while (window.isOpen())
    {
        start = std::chrono::high_resolution_clock::now();

        float deltaTime = deltaClock.restart().asSeconds();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) game.setPaused(!game.isPaused());
        }
        if(Game::isInGame()) game.update(deltaTime);

        window.clear();
        if(Game::isInGame())
        {
            window.setView(game.getCamera().getView(window.getSize()));
            game.render(renderer);
        }

        window.setView(game.getCamera().getUIView(window.getSize()));
        game.renderUI(renderer, window);

        window.display();

        end = std::chrono::high_resolution_clock::now();

        fps = (float)1e9/(float)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

        //std::cout << fps << std::endl;
    }
}
