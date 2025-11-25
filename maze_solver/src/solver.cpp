#include "utils.h"
#include "solver.h"

Solver::Solver(Maze& maze) : maze(maze) {}

void Solver::fill_dead_end(Cell& cell) {
    
    cell.set_filled(true);
    
}

int Solver::count_open_passages(Cell& cell) {
    int c = 0;
    int r = cell.get_row();
    int col = cell.get_col();
    
    std::list<std::string> directions = {"N", "S", "E", "W"};
    
    for (auto d : directions) {

        if (!cell.has_wall(d)) {

            int neighbor_r = r;
            int neighbor_c = col;
            
            if (d == "N") neighbor_r--;
            else if (d == "S") neighbor_r++;
            else if (d == "E") neighbor_c++;
            else if (d == "W") neighbor_c--;
            
            if (neighbor_r >= 0 && neighbor_r < NB_LIGNES && 
                neighbor_c >= 0 && neighbor_c < NB_COLONNES) {
                
                Cell& neighbor = maze.get_cell(neighbor_r, neighbor_c);

                if (!neighbor.is_filled()) {

                    c++;

                }

            }

        }

    }
    
    return c;
    
}

std::list<std::tuple<int, int>> Solver::find_dead_ends() {

    auto [r_d, c_d] = maze.get_depart();
    auto [r_a, c_a] = maze.get_arrive();

    std::list<std::tuple<int, int>> result;

    for (int row = 0; row < NB_LIGNES; row++) {
        for (int col = 0; col < NB_COLONNES; col++) {

            if ((row == r_d && col == c_d) || (row == r_a && col == c_a)) 

                continue;
            
            Cell& cell = maze.get_cell(row, col);

            if (cell.is_filled()) continue;

            int nb_voisins = count_open_passages(cell);

            if (nb_voisins == 1) {

                result.emplace_back(row, col);

            }
        }
    }

    return result;

}

bool Solver::solve_step() {
    
    std::list<std::tuple<int, int>> impasse = find_dead_ends();
        
    if (impasse.empty()) return true;
    
    for (auto [row, col] : impasse) {
        Cell& cell = maze.get_cell(row, col);
        fill_dead_end(cell);
    }
    
    return false;
}