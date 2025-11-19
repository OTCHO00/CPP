#include "boid.h"
#include "flock.h"
#include "utils.h"
#include "simulation.h"
#include <SFML/Graphics.hpp>

Simulation::Simulation() : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Boid Simulation") {

    window.setFramerateLimit(FRAMERATE_LIMIT);

}

void Simulation::handle_events() {

    while (auto event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {

            window.close();

        }
        
        if (const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>()) { 

            Boid new_boid;

            new_boid.set_position(sf::Vector2f(
                static_cast<float>(mousePress->position.x), 
                static_cast<float>(mousePress->position.y)
            ));

            flock.add_boid(new_boid);

        }
    }
}

void Simulation::update() {

    flock.update();

}

void Simulation::render() {

    window.clear();
    flock.render(window);
    window.display();

}

void Simulation::run() {

    while (window.isOpen()) {

        handle_events();
        update();
        render();

    }
    

}