#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Boid {

    private:

        double angle;
        
        sf::Vector2f force;
        sf::Vector2f boid_vitesse;
        sf::Vector2f boid_position;
        sf::Vector2f boid_acceleration;

    public:

        Boid();

        void update();

        void wraparound();

        sf::Vector2f get_vitesse() const;

        sf::Vector2f get_position() const;

        float length(sf::Vector2f v);

        void set_position(sf::Vector2f);

        sf::Vector2f normalize(sf::Vector2f);

        void cohesion(const std::vector<Boid>& voisin);

        void separation(const std::vector<Boid>& voisin);

        void alignement(const std::vector<Boid>& voisin);

        void draw(sf::RenderWindow& window) const;

};