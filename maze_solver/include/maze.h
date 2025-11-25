#pragma once

#include <any>
#include <list>
#include <tuple>
#include <vector>

class Cell; 
namespace sf { class RenderWindow; }

class Maze {

    private :

        int row, col;   
        bool generated, solved;
        
        std::tuple<int,int> depart;
        std::tuple<int,int> arrive;
        std::vector<std::vector<Cell>> maze;

    public :

        Maze(int row, int col);

        std::tuple<int, int> get_depart();

        std::tuple<int, int> get_arrive();

        Cell& get_cell(int row, int col);

        void draw(sf::RenderWindow& window);

        void generate_recursive_backtracking();

        void remove_wall_between(Cell cell1, Cell cell2);

        std::list<std::tuple<int, int>> get_voisins(Cell cell);

        std::list<std::tuple<int, int>> get_voisins_inconnus(Cell cell);

};  


