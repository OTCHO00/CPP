#pragma once

#include <map>
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;

class Cell {

    private: 

        bool walls[4];
        bool filled, visited;   
        int row, col, parent;
        std::tuple<int, int> position;

    public:

        Cell(int row, int col);

        int get_col();

        int get_row();

        void set_filled(bool f);
    
        bool is_visited() const;

        bool is_filled() const;

        void set_visited(bool v);

        std::tuple<int, int> get_position();
        
        void set_wall(std::string direction);

        bool has_wall(const std::string& direction) const;

        void remove_wall(std::string direction);

        void draw(sf::RenderWindow& window);


};