#include <cmath>
#include <vector>
#include <random>

#include "boid.h"
#include "utils.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Boid::Boid() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib_a(0, 2 * M_PI);

    angle = distrib_a(gen);

    boid_position = sf::Vector2f(0.0f, 0.0f);
    boid_acceleration = sf::Vector2f(0.0f, 0.0f);
    boid_vitesse = sf::Vector2f(cos(angle) * VITESSE_INIT, sin(angle) * VITESSE_INIT);

}

sf::Vector2f Boid::get_position() const {

    return boid_position;

}

sf::Vector2f Boid::get_vitesse() const {

    return boid_vitesse;

}

void Boid::set_position(sf::Vector2f new_position) {

    boid_position = new_position;

}

float Boid::length(sf::Vector2f v) {

    return sqrt(v.x * v.x + v.y * v.y);

}

sf::Vector2f Boid::normalize(sf::Vector2f vecteur) {

    float l = length(vecteur);
    if (l <= 0.00001f) return sf::Vector2f(0.0f, 0.0f);
    return sf::Vector2f(vecteur.x / l, vecteur.y / l);
    
}

void Boid::separation(const std::vector<Boid>& voisins) {

    sf::Vector2f somme(0.0f, 0.0f);
    int nb_voisins = 0;

    for (auto& voisin : voisins) {

        float distance = length(get_position() - voisin.get_position());

        if (0 < distance && distance <= RAYON_SEPARATION) {

            float diff_x = (get_position().x - voisin.get_position().x) / distance;
            float diff_y = (get_position().y - voisin.get_position().y) / distance;

            somme.x += diff_x;
            somme.y += diff_y;
            nb_voisins += 1;

        }

    }

        if (nb_voisins > 0) {

            sf::Vector2f moyenne(somme.x / nb_voisins, somme.y / nb_voisins);

            if (length(moyenne) > 0) {

                sf::Vector2f force_separation( 
                    normalize(moyenne).x * FORCE_MAX * POIDS_SEPARATION,
                    normalize(moyenne).y * FORCE_MAX * POIDS_SEPARATION
                );

                boid_acceleration.x += force_separation.x;
                boid_acceleration.y += force_separation.y;

            }

        }

}

void Boid::alignement(const std::vector<Boid>& voisins) {

    sf::Vector2f somme(0.0f, 0.0f);
    int nb_voisins = 0;

    for (auto& voisin : voisins) {

        float distance = length(get_position() - voisin.get_position());

        if (0 < distance && distance <= RAYON_ALIGNEMENT) {

            somme.x += voisin.get_vitesse().x;
            somme.y += voisin.get_vitesse().y;
            nb_voisins += 1;

        }

    }

        if (nb_voisins > 0) {

            sf::Vector2f vitesse_moyenne(somme.x / nb_voisins, somme.y / nb_voisins);
            sf::Vector2f f(vitesse_moyenne.x - boid_vitesse.x, vitesse_moyenne.y - boid_vitesse.y);

            if (length(f) > 0) {

                sf::Vector2f force_alignement(
                    normalize(f).x * FORCE_MAX * POIDS_ALIGNEMENT,  
                    normalize(f).y * FORCE_MAX * POIDS_ALIGNEMENT
                );
                boid_acceleration.x += force_alignement.x;
                boid_acceleration.y += force_alignement.y;

            }

        }

    

}

void Boid::cohesion(const std::vector<Boid>& voisins) {

    sf::Vector2f somme(0.0f, 0.0f);
    int nb_voisins = 0;

    for (auto& voisin : voisins) {

        float distance = length(get_position() - voisin.get_position());

        if (0 < distance && distance <= RAYON_COHESION) {

            somme.x += voisin.get_position().x;
            somme.y += voisin.get_position().y;
            nb_voisins += 1;

        }

    }

        if (nb_voisins > 0) {

            sf::Vector2f position_moyenne(somme.x / nb_voisins, somme.y / nb_voisins);
            sf::Vector2f f(position_moyenne.x - boid_position.x, position_moyenne.y - boid_position.y);

            if (length(f) > 0) {

                sf::Vector2f force_cohesion(
                    normalize(f).x * FORCE_MAX * POIDS_COHESION,  
                    normalize(f).y * FORCE_MAX * POIDS_COHESION
                );
                boid_acceleration.x += force_cohesion.x;
                boid_acceleration.y += force_cohesion.y;

            }

        }

}

void Boid::update() {

    boid_vitesse.x += boid_acceleration.x;
    boid_vitesse.y += boid_acceleration.y;

    if (length(boid_vitesse) > VITESSE_MAX) {

        boid_vitesse.x = normalize(boid_vitesse).x * VITESSE_MAX;
        boid_vitesse.y = normalize(boid_vitesse).y * VITESSE_MAX;

    } 

    else if (length(boid_vitesse) < VITESSE_MIN && length(boid_vitesse) > 0) {

        boid_vitesse.x = normalize(boid_vitesse).x * VITESSE_MIN;
        boid_vitesse.y = normalize(boid_vitesse).y * VITESSE_MIN;

    }

    boid_position.x += boid_vitesse.x;
    boid_position.y += boid_vitesse.y;
    boid_acceleration = sf::Vector2f(0.0f, 0.0f);

    wraparound();
    
}

void Boid::wraparound() {

    if (boid_position.x >= WINDOW_WIDTH) boid_position.x = 0;
    else if (boid_position.x < 0) boid_position.x = WINDOW_WIDTH;

    if (boid_position.y >= WINDOW_HEIGHT) boid_position.y = 0;
    else if (boid_position.y < 0) boid_position.y = WINDOW_HEIGHT;

}

void Boid::draw(sf::RenderWindow& window) const {

    auto angle_deg = atan2(boid_vitesse.y, boid_vitesse.x) * 180.0f / M_PI;
    
    sf::ConvexShape boid;
    boid.setPointCount(3);

    boid.setPoint(0, sf::Vector2f(BASE_BOIDS_1));
    boid.setPoint(1, sf::Vector2f(BASE_BOIDS_2));
    boid.setPoint(2, sf::Vector2f(TIP_BOIDS));

    boid.setFillColor(sf::Color::Red);

    float center_x = (TIP_BOIDS.x + BASE_BOIDS_1.x + BASE_BOIDS_2.x) / 3.0f;
    float center_y = (TIP_BOIDS.y + BASE_BOIDS_1.y + BASE_BOIDS_2.y) / 3.0f;

    boid.setOrigin(sf::Vector2f(center_x, center_y));
    boid.setPosition(boid_position);
    boid.setRotation(sf::degrees(angle_deg + 90.0f));

    window.draw(boid);

}