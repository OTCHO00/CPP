#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Boid {

    private:

        double angle;

        sf::Vector2f force;
        sf::Vector2f boid_vitesse;
        sf::Vector2f boid_position;
        sf::Vector2f boid_acceleration;

    public:

        Boid();

        void edges();

        void update();

        void cohesion(Boid boid);

        void separation(Boid boid);

        void alignement(Boid boid);

        void draw(sf::RenderWindow& window) const;

        void apply_force(sf::Vector2f force);

};