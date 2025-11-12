#pragma once
#include <vector>
#include "utils.h" 
#include <SFML/Graphics.hpp>

struct Segment {

    int x, y;
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {

    private:

        std::vector<Segment> snake_body;
        Direction current_direction;
        bool is_alive;

    public:

        Snake();

        void deplacement();

        void set_direction(Direction new_direction);

        void update();

        void grow();

        bool check_food_collision(const Segment& food_pos) const;

        bool check_wall_collision() const;    

        bool check_self_collision() const;

        bool get_is_alive() const;   

        void draw(sf::RenderWindow& window);
};