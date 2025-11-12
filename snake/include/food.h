#include <iostream>
#include <random>
#include "util.h"

class Food {
    
    private:

        int x, y;
        bool is_eaten;

    public:
    
        Food();
        
        ~Food();
};

    Food::Food(){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribx(0, LARGEUR);
        std::uniform_int_distribution<> distriby(0, HAUTEUR);

        x = distribx(gen);
        y = distriby(gen);
        is_eaten = false;

    }

    Food::~Food(){

    }
