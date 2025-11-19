#pragma once
#include "boid.h"
#include "flock.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

class Simulation {

    private:

        Flock flock;
        sf::RenderWindow window;

    public:

        Simulation();

        void run();

        void update();

        void render();

        void handle_events();

};