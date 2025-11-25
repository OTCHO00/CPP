#include <map>
#include "cell.h"
#include "utils.h"
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace sf;

Cell::Cell(int row, int col) : row(row), col(col), filled(false), parent(-1), visited(false), position({row, col}){

    walls[0] = true;  
    walls[1] = true; 
    walls[2] = true;  
    walls[3] = true;  

}

void Cell::set_visited(bool v) {

    visited = v;

}

void Cell::set_filled(bool f) {

    filled = f;

}

bool Cell::is_visited() const {

    return visited;

}

bool Cell::is_filled() const {

    return filled;

}

int Cell::get_col() {

    return col;

}

int Cell::get_row() {

    return row;

}

bool Cell::has_wall(const std::string& direction) const {

    if (direction == "N") return walls[0];
    if (direction == "S") return walls[1];
    if (direction == "E") return walls[2];
    if (direction == "W") return walls[3];

    return true;  

}

void Cell::remove_wall(std::string direction) {

    if (direction == "N") walls[0] = false;
    else if (direction == "S") walls[1] = false;
    else if (direction == "E") walls[2] = false;
    else if (direction == "W") walls[3] = false;

}


void Cell::draw(sf::RenderWindow& window) {

    float x = col * TAILLE_CELLULE;
    float y = row * TAILLE_CELLULE;


    if (filled) {

        sf::RectangleShape square(sf::Vector2f(TAILLE_CELLULE, TAILLE_CELLULE));
        square.setPosition({x, y});
        square.setFillColor(sf::Color(0, 255, 0, 128));
        window.draw(square);

    }

    sf::VertexArray lines(sf::PrimitiveType::Lines);

    if (has_wall("N")) {
        sf::Vertex v1, v2;
        v1.position = sf::Vector2f(x, y);
        v1.color = sf::Color::White;
        v2.position = sf::Vector2f(x + TAILLE_CELLULE, y);
        v2.color = sf::Color::White;
        lines.append(v1);
        lines.append(v2);
    }

    if (has_wall("S")) {
        sf::Vertex v1, v2;
        v1.position = sf::Vector2f(x, y + TAILLE_CELLULE);
        v1.color = sf::Color::White;
        v2.position = sf::Vector2f(x + TAILLE_CELLULE, y + TAILLE_CELLULE);
        v2.color = sf::Color::White;
        lines.append(v1);
        lines.append(v2);
    }

    if (has_wall("E")) {
        sf::Vertex v1, v2;
        v1.position = sf::Vector2f(x + TAILLE_CELLULE, y);
        v1.color = sf::Color::White;
        v2.position = sf::Vector2f(x + TAILLE_CELLULE, y + TAILLE_CELLULE);
        v2.color = sf::Color::White;
        lines.append(v1);
        lines.append(v2);
    }

    if (has_wall("W")) {
        sf::Vertex v1, v2;
        v1.position = sf::Vector2f(x, y);
        v1.color = sf::Color::White;
        v2.position = sf::Vector2f(x, y + TAILLE_CELLULE);
        v2.color = sf::Color::White;
        lines.append(v1);
        lines.append(v2);
    }

    window.draw(lines);
}