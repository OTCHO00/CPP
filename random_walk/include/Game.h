#pragma once
#include "RandomWalk.h"
#include <SFML/Graphics.hpp>

class Game {

    private: 
    
        RandomWalk randomWalk;
        sf::RenderWindow window;      
        std::vector<RandomWalk> walks;

    public: 

        Game();

        void run();

        void render();

        void update();

};