#include "RigidBody.h"

RigidBody::RigidBody(Vec2 position, float mass, Shape* shape) : mass(mass), shape(shape), position(position), velocity(0, 0), acceleration(0, 0), is_static(false){}

void RigidBody::apply_force(const Vec2& force) {

    acceleration = Vec2(force.x / mass, force.y / mass);

}

void RigidBody::update(float dt) {

    Vec2 delta = acceleration * dt;
    velocity = velocity + delta;

    position = position + velocity * dt;

    acceleration = Vec2(0, 0);
    
}   
