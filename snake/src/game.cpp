#include "game.h"
#include "snake.h"
#include "food.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

Game::Game()
    : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Snake") {

    window.setFramerateLimit(FRAMERATE_LIMIT);
}

void Game::handle_events() {
    
    while (auto event = window.pollEvent()) {

        if (auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            if (keyPressed->code == sf::Keyboard::Key::Up) {
                snake.set_direction(UP);
            } else if (keyPressed->code == sf::Keyboard::Key::Down) {
                snake.set_direction(DOWN);
            } else if (keyPressed->code == sf::Keyboard::Key::Left) {
                snake.set_direction(LEFT);
            } else if (keyPressed->code == sf::Keyboard::Key::Right) {
                snake.set_direction(RIGHT);
            }
        }

        if (event->is<sf::Event::Closed>()) {

             window.close();

        }

    }

}

void Game::update() {

    snake.update();
    
    if (snake.check_food_collision(food.get_position())) {

        snake.grow();
        food.randomize_position();

    }

}


void Game::render(){
    
    window.clear();
    food.draw(window);
    snake.draw(window);
    window.display(); 

}

void Game::run() {

    while (snake.get_is_alive()) {
                
        handle_events();
        update();
        render();

    }

}