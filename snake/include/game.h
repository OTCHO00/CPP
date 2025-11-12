#pragma once
#include "snake.h"
#include "food.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

class Game {

    private:

        Food food;
        Snake snake;
        sf::RenderWindow window;

    public:

        Game();

        void run();

        void handle_events();

        void update();

        void render();

};