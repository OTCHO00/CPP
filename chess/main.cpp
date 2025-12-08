#include <SFML/Graphics.hpp>
#include "Plateau.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Test Plateau");

    Plateau plateau;

    while (window.isOpen())
    {
        // Récupérer les événements
        while (auto eventOpt = window.pollEvent())
        {
            sf::Event event = *eventOpt;  // Déballer l'optional

            // Vérifier si l'événement est la fermeture de la fenêtre
            if (event.is<sf::Event::Closed>()) {       // SFML 3 utilise isClosed()
                window.close();
            }
        }

        window.clear();
        plateau.draw(window);
        window.display();
    }

    return 0;
}