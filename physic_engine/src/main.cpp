#include <iostream>
#include "math/Vec2.h"
#include "physics/RigidBody.h"
#include "physics/shapes/Circle.h"
#include "physics/collision/CollisionDetector.h"
#include "physics/collision/CollisionResolver.h"

int main() {
    Circle* shape1 = new Circle(50.0f);
    Circle* shape2 = new Circle(50.0f);

    RigidBody ball1(Vec2(0, 0), 1.0f, shape1);
    RigidBody ball2(Vec2(80, 0), 1.0f, shape2);

    // Ils foncent l'un vers l'autre
    ball1.velocity = Vec2(100, 0);
    ball2.velocity = Vec2(-100, 0);

    // Simulation
    for (int i = 0; i < 100; i++) {
        ball1.update(1.0f / 60.0f);
        ball2.update(1.0f / 60.0f);
        
        if (CollisionDetector::CheckCollision_CircleCircle(&ball1, &ball2)) {
            CollisionResolver::ResolveCollision(&ball1, &ball2);
            std::cout << "Frame " << i << " - COLLISION !" << std::endl;
            std::cout << "  Ball1 velocity: " << ball1.velocity.x << std::endl;
            std::cout << "  Ball2 velocity: " << ball2.velocity.x << std::endl;
        }
    }
    
    return 0;
}