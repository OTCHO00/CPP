#pragma once
#include "boid.h"
#include <SFML/Graphics.hpp>

class Flock {

    private:

        std::vector<Boid> boids;

    public:

    Flock();

    void update();

    void remove_boid();

    void add_boid(const Boid& boid);

    void render(sf::RenderWindow& window) const;

};