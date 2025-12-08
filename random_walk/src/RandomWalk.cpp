#include <SFML/Graphics.hpp>
#include "../include/RandomWalk.h"

#define CELL_SIZE 4
#define HEIGHT 1000
#define WIDTH 700

RandomWalk::RandomWalk() : interval(0.01f), currentColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1), position({HEIGHT / (2 * CELL_SIZE), WIDTH / (2 * CELL_SIZE)}){}   

sf::Vector2<int> RandomWalk::randomChoice() {

    int choice = rand() % 4;

    switch (choice) {

    case 0:
        
        return sf::Vector2<int>(-1, 0);
    
    case 1:
        
        return sf::Vector2<int>(1, 0);
    
    case 2:
        
        return sf::Vector2<int>(0, -1);
    
    case 3:
        
        return sf::Vector2<int>(0, 1);
    
    default:
        
        return sf::Vector2<int>(0, 0);
    }

}

void RandomWalk::update() {

    if (clock.getElapsedTime().asSeconds() >= interval) {

        sf::Vector2<int> choice = randomChoice();

        this->position.x += choice.x;
        this->position.y += choice.y;
        
        clock.restart();

    }

}

void RandomWalk::draw(sf::RenderWindow& window) {

    sf::RectangleShape rect;
    rect.setFillColor(currentColor);
    rect.setSize({CELL_SIZE, CELL_SIZE});
    rect.setPosition(sf::Vector2f(this->position.x * CELL_SIZE, this->position.y * CELL_SIZE));  
    window.draw(rect);
    
}