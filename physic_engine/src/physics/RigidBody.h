#pragma once
#include "math/Vec2.h"
#include "shapes/Shape.h"

class RigidBody {

    public:

        float mass;
        Shape* shape;
        bool is_static;
        Vec2 position, velocity, acceleration;


        void update(float dt);
        void apply_force(const Vec2& force);
        RigidBody(Vec2 position, float mass, Shape* shape);

};
