#pragma once
#include "utils.h"

#include <set>
#include <utility>
#include <SFML/Graphics.hpp>

using namespace std;

class Grid {

    private:
        
        int row, col;
        int nb_generation;
        set<pair<int, int>> cels;

    public:

        Grid();

        void clear();

        void update();

        int get_len_cels();

        void insert_pattern();

        set<pair<int, int>> get_cels();

        bool get_cell(int row, int col);

        void toggle_cell(int row, int col);

        int count_voisins(int row, int col);

        void draw(sf::RenderWindow& window);

        void set_cell(int row, int col, bool state);

        bool apply_rules(int row, int col, int nb_voisins);

};
