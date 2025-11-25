#include <list>
#include <deque>
#include <tuple>
#include <vector>
#include <random>

#include "maze.h"
#include "cell.h"
#include "utils.h"

using namespace std;

Maze::Maze(int row, int col) : row(row), col(col), generated(false), solved(false) {

    this->depart = {0, 0};
    this->arrive = {row - 1 , col - 1};

    maze.reserve(row);

    for (int r = 0; r < row; r++){

        vector<Cell> ligne;
        ligne.reserve(col);

        for (int c = 0; c < col; c++){

            ligne.push_back(Cell(r, c));

        }

        maze.push_back(ligne);

    }   

}   

Cell& Maze::get_cell(int row, int col) {

    return maze[row][col];

}

std::tuple<int, int> Maze::get_depart() {

    auto [r, c] = depart;
    return {r, c};

}

std::tuple<int, int> Maze::get_arrive() {

    auto [r, c] = arrive;
    return {r, c};

}

std::list<std::tuple<int, int>> Maze::get_voisins(Cell cell) {

    std::list<std::tuple<int,int>> voisins;

    if (0 <= cell.get_row() - 1 && cell.get_row() - 1 < row && 0 <= cell.get_col() && cell.get_col() < col) {

        voisins.push_back({cell.get_row() - 1, cell.get_col()});

    }

    if (0 <= cell.get_row() + 1 && cell.get_row() + 1 < row && 0 <= cell.get_col() && cell.get_col() < col) {

        voisins.push_back({cell.get_row() + 1, cell.get_col()});

    }

    if (0 <= cell.get_row() && cell.get_row() < row && 0 <= cell.get_col() + 1 && cell.get_col() + 1 < col) {

        voisins.push_back({cell.get_row(), cell.get_col() + 1});

    }

    if (0 <= cell.get_row() && cell.get_row() < row && 0 <= cell.get_col() - 1 && cell.get_col() - 1 < col) {

        voisins.push_back({cell.get_row(), cell.get_col() - 1});

    }

    return voisins;

}

std::list<std::tuple<int, int>> Maze::get_voisins_inconnus(Cell cell) {

    std::list<std::tuple<int,int>> voisins = get_voisins(cell);
    std::list<std::tuple<int,int>> inconnus;

    for (auto [r, c] : voisins) {

        Cell voisin = get_cell(r, c);

        if (!voisin.is_visited()) {

            inconnus.push_back({r, c});
            
        }

    }

    return inconnus;

}

void Maze::remove_wall_between(Cell cell1, Cell cell2) {

    int r1 = cell1.get_row();
    int c1 = cell1.get_col();
    int r2 = cell2.get_row();
    int c2 = cell2.get_col();

    if (r2 < r1) {

        maze[r1][c1].remove_wall("N");  
        maze[r2][c2].remove_wall("S");

    }
    
    if (r2 > r1) {

        maze[r1][c1].remove_wall("S");
        maze[r2][c2].remove_wall("N");

    }
    
    if (c2 > c1) {

        maze[r1][c1].remove_wall("E");
        maze[r2][c2].remove_wall("W");

    }
    
    if (c2 < c1) {

        maze[r1][c1].remove_wall("W");
        maze[r2][c2].remove_wall("E");

    }
}

void Maze::generate_recursive_backtracking() {

    std::deque<std::tuple<int, int>> pile;
    auto [r, c] = depart;

    maze[r][c].set_visited(true);
    pile.push_back({r, c});

    while(!pile.empty()) {

        auto [row, col] = pile.back();
        Cell& sommet = maze[row][col];
        std::list<std::tuple<int, int>> voisins_non_visite = get_voisins_inconnus(sommet);

        if (!voisins_non_visite.empty()) {

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, voisins_non_visite.size() - 1);

            auto it = voisins_non_visite.begin();
            std::advance(it, dist(gen));
            auto [vrow, vcol] = *it;

            remove_wall_between(sommet, maze[vrow][vcol]);
            maze[vrow][vcol].set_visited(true);
            pile.push_back({vrow, vcol});

        }

        else {

            pile.pop_back();

        }

    }

    generated = true;

}

void Maze::draw(sf::RenderWindow& window) {

    for (auto& ligne : maze) {
        for (auto& cell : ligne) {

            cell.draw(window);

        }

    }

}