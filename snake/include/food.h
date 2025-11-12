#pragma once
#include "snake.h"
#include "utils.h" 
#include <SFML/Graphics.hpp>

class Food {
    
    private:

        int x, y;

    public:
    
        Food();
        
        Segment get_position() const;

        void randomize_position();

        void draw(sf::RenderWindow& window);    

};
