#include <tuple>
#include <vector>

#include "grid.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Grid::Grid() {

    row = NB_LIGNES;
    col = NB_COLONNES;

    nb_generation = 0;

}

set<pair<int, int>> Grid::get_cels() {

    return cels;

}

bool Grid::get_cell(int row, int col) {

    return cels.count({row, col}) > 0;

}

void Grid::set_cell(int row, int col, bool state) {

    if (cels.count({row, col}) && state == false) {

        cels.erase({row, col});

    }

    if (!cels.count({row, col}) && state == true) {

        cels.insert({row, col});

    }

}

void Grid::toggle_cell(int row, int col) {

    if (cels.count({row, col})) {

        cels.erase({row, col});

    }

    else {

        cels.insert({row, col});

    }

}

int Grid::count_voisins(int row, int col) {

    int nb_voisins = 0;
    std::vector<std::tuple<int, int>> direction = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, -1},
        {1, 1},
        {-1, 1},
        {1, -1},
    };

    for (auto &[x, y] : direction) {

        int r = row + x;
        int c = col + y;

        if (0 <= r && r < this->row && 0 <= c && c < this->col && cels.count({r, c})) {

            nb_voisins += 1;

        }

    }

    return nb_voisins;

}

bool Grid::apply_rules(int row, int col, int nb_voisins) {

    if (get_cell(row, col)) {

        if (nb_voisins == 0 || nb_voisins == 1 || nb_voisins >= 4) {

            return false;

        }

        if (nb_voisins == 2 || nb_voisins == 3) {

            return true;

        }

    }

    else {

        if (nb_voisins == 3) {

            return true;

        }

        else {

            return false;

        }

    }

    return false;

}

int Grid::get_len_cels() {

    return cels.size();

}

void Grid::clear() {

    nb_generation = 0;
    cels.clear();

}

void Grid::update() {

    set<pair<int, int>> new_cels;

    for (int x = 0; x <= row; x ++) {
        for (int y = 0; y <= col; y ++){

            int nb_voisin = count_voisins(x, y);

            if (apply_rules(x, y, nb_voisin)) {

                new_cels.insert({x, y});

            }

        }

    }

    cels = new_cels;
    nb_generation += 1;

}

void Grid::draw(sf::RenderWindow& window) {

    for (int r = 0; r < NB_LIGNES; r ++) {
        for (int c = 0; c < NB_COLONNES; c ++) {

            if (get_cell(r, c)) {

                float pixel_x = c * TAILLE_CELLULE;
                float pixel_y = r * TAILLE_CELLULE;

                sf::RectangleShape cel(sf::Vector2f(TAILLE_CELLULE, TAILLE_CELLULE));
                cel.setPosition(sf::Vector2f(static_cast<float>(pixel_x), static_cast<float>(pixel_y)));

                window.draw(cel);

            }   

        }

    }

}