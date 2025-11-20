#pragma once
#include "grid.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

class Game {

    private:

        int FPS;
        Grid grid;
        bool simulation;
        sf::RenderWindow window;

    public:

        Game();

        void run();

        void update();

        void render();

        void handle_events();

};