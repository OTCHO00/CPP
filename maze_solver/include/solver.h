#pragma once

#include <any>
#include <list>
#include <tuple>
#include <vector>

#include "maze.h"
#include "cell.h"
#include "utils.h"

class Solver {


    public :

        Maze& maze;

        Solver(Maze& maze);

        bool solve_step();

    private :

        void fill_dead_end(Cell& cell);

        std::list<std::tuple<int, int>> find_dead_ends();

        int count_open_passages(Cell& cell);

}; 