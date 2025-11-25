#pragma once

#include "cell.h"
#include "maze.h"
#include "utils.h"
#include "solver.h"
#include <SFML/Graphics.hpp>

class Game {

    private:

        Maze maze;
        float delay;
        bool solving;
        Solver solver;
        sf::Clock clock;
        sf::RenderWindow window;

    public:

        Game();

        void run();

        void render();

        void update();

        void handle_events();

};