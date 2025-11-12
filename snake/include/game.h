#pragma once
#include <SFML/Window.hpp>

namespace sf { class Window; }

class Game {

    private:

        sf::Clock clock;
        sf::Window* window;
        sf::Time timeStep;
        sf::Time accumulator = sf::Time::Zero;
        int ticks = 0;

    public:

        Game();
        ~Game();

        void run(){

            while (window->isOpen()){

                sf::Time dt = clock.restart();
                accumulator += dt;

                while (accumulator > timeStep) {

                    accumulator -= timeStep;

                }
            }

        }
};

    Game::Game() {

        window = new sf::Window(sf::VideoMode(LARGEUR, HAUTEUR), "Snake");
        window->setTitle("Snake Game");
        window->setVerticalSyncEnabled(true);
        sf::Time timeStep = sf::seconds(1.f / 60.f);
        sf::Time accumulator = sf::Time::Zero;
    }