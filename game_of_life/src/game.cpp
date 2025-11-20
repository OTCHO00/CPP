#include "grid.h"
#include "game.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode({LARGEUR, HAUTEUR}), "Game of Life"), FPS(60), simulation(false) {
    
    window.setFramerateLimit(FPS);

}

void Game::handle_events() {
    
    while (auto event = window.pollEvent()) {

        if (auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            if (keyPressed->code == sf::Keyboard::Key::Space) {

                grid.clear();

            } 

            if (keyPressed->code == sf::Keyboard::Key::S) {

                simulation = !simulation;

            } 

            if (keyPressed->code == sf::Keyboard::Key::Right) {

                FPS += 2;

            } 

            if (keyPressed->code == sf::Keyboard::Key::Left) {

                FPS -= 2;

                if (FPS < 1) {

                    FPS = 1;

                }

            }

        }

        if (const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>()) { 

            int x = mousePress->position.x;
            int y = mousePress->position.y;

            grid.toggle_cell(y / TAILLE_CELLULE, x / TAILLE_CELLULE);

        }

        if (event->is<sf::Event::Closed>()) {

             window.close();

        }

    }

}

void Game::update() {

    if (simulation) {
    
        grid.update();

    }

}

void Game::render() {

    window.clear(sf::Color::Black);
    grid.draw(window);
    window.display();             

}

void Game::run() {

    while (window.isOpen()) {

        handle_events();
        update();
        render();

    }
    
}