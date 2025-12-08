#include "../include/Game.h"
#include <SFML/Graphics.hpp>

#define HEIGHT 1000
#define WIDTH 700
#define FPS 60

Game::Game() : window(sf::VideoMode({WIDTH, HEIGHT}), "Random Walk") {

    window.setFramerateLimit(FPS);

    for (int i = 0; i < 5; i++) {

        walks.push_back(RandomWalk());

    }

}

void Game::update() {

    for (auto& walk : walks) {
        walk.update();

    }
}

void Game::render() {
    
    for (auto& walk : walks) {

        walk.draw(window);

    }

    window.display();

}

void Game::run() {

    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            
            if (event->is<sf::Event::Closed>()) {

                window.close();

            }

        }
        
        update();
        render();

    }
    

}