#ifndef UTILS_H
#define UTILS_H

// Fenêtre
constexpr int WINDOW_WIDTH = 1300;
constexpr int WINDOW_HEIGHT = 950;
constexpr unsigned int FRAMERATE_LIMIT = 60;

// Boids
constexpr float VITESSE_INIT = 5.0;
constexpr float VITESSE_MAX = 8.0;
constexpr float VITESSE_MIN = 3.0;
constexpr float FORCE_MAX = 0.2;

constexpr int RAYON_SEPARATION = 40;
constexpr int RAYON_ALIGNEMENT = 50;
constexpr int RAYON_COHESION = 70;

constexpr float POIDS_SEPARATION = 2.0;
constexpr float POIDS_COHESION = 0.7;
constexpr float POIDS_ALIGNEMENT = 1.2;

constexpr int WIDTH_BOIDS = 15;
constexpr int HEIGHT_BOIDS = 15;
const sf::Vector2f TIP_BOIDS(HEIGHT_BOIDS / 2, 0);
const sf::Vector2f BASE_BOIDS_1(-HEIGHT_BOIDS / 2, -WIDTH_BOIDS / 2);
const sf::Vector2f BASE_BOIDS_2(-HEIGHT_BOIDS / 2, WIDTH_BOIDS / 2);

#endif