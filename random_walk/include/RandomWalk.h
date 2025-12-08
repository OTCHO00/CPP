#pragma once 
#include <vector>
#include <SFML/Graphics.hpp>

class RandomWalk {

    private: 

        float interval;
        sf::Clock clock;
        sf::Color currentColor;
        sf::Vector2<int> position;

    public:

        RandomWalk();

        void update();

        sf::Color setColor();

        sf::Vector2<int> randomChoice();

        void draw(sf::RenderWindow& window);

};