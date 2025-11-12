#include "snake.h"
#include "util.h"
#include <vector>

Snake::Snake() {

    current_direction = RIGHT;
    Segment head;
    head.x = 5;
    head.y = 5;
    is_alive = true;
    snake_body.push_back(head);
}

void Snake::deplacement() {

    Segment new_head;
    new_head.x = snake_body.front().x;
    new_head.y = snake_body.front().y;

    if (current_direction == UP) {

        new_head.y -= 1;

    } else if (current_direction == DOWN) {

        new_head.y += 1;

    } else if (current_direction == LEFT) {

        new_head.x -= 1;

    } else if (current_direction == RIGHT) {

        new_head.x += 1;

    }

    snake_body.insert(snake_body.begin(), new_head);
    snake_body.pop_back();
   
}

void Snake::set_direction(Direction new_direction) {

    if (current_direction == LEFT and new_direction == RIGHT) {

        current_direction = LEFT;

    } else if (current_direction == RIGHT and new_direction == LEFT) {

        current_direction = RIGHT;
        
    } else if (current_direction == UP and new_direction == DOWN) {

        current_direction = UP;
        
    } else if (current_direction == DOWN and new_direction == UP) {

        current_direction = DOWN;
        
    } else {

        current_direction = new_direction;

    }
        
}

bool Snake::get_is_alive() const {

    return is_alive;

}

void Snake::grow() {

    snake_body.push_back(snake_body.back());

}

bool Snake::check_food_collision(const Segment& food_pos) const {

    return (snake_body.front().x == food_pos.x && snake_body.front().y == food_pos.y);

}

bool Snake::check_wall_collision() const {

    return (snake_body.front().x < 0 || snake_body.front().x >= LARGEUR || snake_body.front().y < 0 || snake_body.front().y >= HAUTEUR);

}

bool Snake::check_self_collision() const {

    for (int i = 1; i < snake_body.size(); i++) {

        if (snake_body.front().x == snake_body[i].x && snake_body[i].y == snake_body.front().y) {

            return true;

        }  

    }

    return false;  

}

void Snake::update() {

    if (!is_alive) return;

    deplacement();

    if (check_self_collision() || check_wall_collision()) {

        is_alive = false;

    }

}