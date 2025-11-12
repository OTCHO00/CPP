#pragma once
#include <iostream>


struct Segment {

    int x, y;
};


class Snake {

    private:

        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        std::vector<Segment> snake_body;

    public:

        Snake();

        void deplacement();

        void set_direction();

        void update();

        void grow();

        void check_food_collision();

        void check_wall_collision();

        void check_self_collision();

        void draw() const;
};