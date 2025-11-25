#include "game.h"
#include "utils.h"
#include "maze.h"
#include "cell.h"
#include "solver.h"
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode({WIDTH, HEIGHT}), "Maze"), maze(NB_LIGNES, NB_COLONNES), solver(maze), solving(true), delay(0.2) {

    window.setFramerateLimit(FPS);
    maze.generate_recursive_backtracking();
}

void Game::handle_events() {

    while (auto event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {

             window.close();

        }

    }

}

void Game::update() {

    if (solving) {

        if (clock.getElapsedTime().asSeconds() >= delay) {

            if (solver.solve_step()) {

                solving = false;

            } 

            clock.restart();

        }

    }

}

void Game::render(){
    
    window.clear();
    maze.draw(window);
    window.display(); 

}

void Game::run() {

    while (window.isOpen()) {
                
        handle_events();
        update();
        render();

    }

}