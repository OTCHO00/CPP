#include "food.h"
#include "utils.h"
#include <random>
#include <SFML/Graphics.hpp>

Food::Food() {

    randomize_position();

}

Segment Food::get_position() const {

    return {x, y};

}

void Food::randomize_position() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_x(0, GRID_WIDTH - 1);
    std::uniform_int_distribution<> distrib_y(0, GRID_HEIGHT - 1);

    x = distrib_x(gen);
    y = distrib_y(gen);

}

void Food::draw(sf::RenderWindow& window) {

    const float cell_size = static_cast<float>(CELL_SIZE);

    sf::CircleShape cercle(cell_size / 2.f);
    cercle.setPosition(sf::Vector2f(x * cell_size, y * cell_size));
    cercle.setFillColor(sf::Color::Red);
    window.draw(cercle);

}