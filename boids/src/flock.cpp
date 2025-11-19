    #include "boid.h"
    #include "flock.h"
    #include <SFML/Graphics.hpp>

    Flock::Flock() {}

    void Flock::add_boid(const Boid& boid) {

        boids.push_back(boid);

    }

    void Flock::remove_boid() {

        boids.pop_back();

    }

    void Flock::update() {

        for (auto& boid : boids) {

            boid.separation(boids);
            boid.alignement(boids);
            boid.cohesion(boids);
            boid.update();

        }

    }

    void Flock::render(sf::RenderWindow& window) const {

        for (const auto& boid : boids) {

            boid.draw(window);

        }

    }