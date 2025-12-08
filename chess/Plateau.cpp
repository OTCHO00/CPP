#include "Piece/Piece.h"
#include "Plateau.h"
#include <SFML/Graphics.hpp>

Plateau::Plateau(){}

void Plateau::draw(sf::RenderWindow& window) {

    const int row = 8;
    const int col = 8;
    const int cellSize = 50;

    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);

    for (int r = 0; r < row; ++r) {

        for (int c = 0; c < col; ++c) {

            cell.setPosition(sf::Vector2f(r * cellSize, c * cellSize));

            if ((r + c) % 2 == 0) {

                cell.setFillColor(sf::Color::White);

            }

            window.draw(cell);

        }

    }

    window.display();

}