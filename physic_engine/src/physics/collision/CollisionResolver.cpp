#include <iostream>
#include "math/Vec2.h"
#include "shapes/Circle.h"
#include "CollisionResolver.h"

void CollisionResolver::ResolveCollision(RigidBody* a, RigidBody* b) {

    float restitution = 0.5f;

    Vec2 diff = b->position - a->position;
    float distance = diff.length();

    Vec2 normal = (distance > 0) ? diff / distance : Vec2(1, 0);

    Circle* ca = static_cast<Circle*>(a->shape);
    Circle* cb = static_cast<Circle*>(b->shape);

    float penetration = (ca->radius + cb->radius) - distance;

    Vec2 correction = normal * (penetration / 2.0f);
    a->position -= correction;
    b->position += correction;

    // Relative velocity
    Vec2 relativeVelocity = b->velocity - a->velocity;
    float velocityAlongNormal = relativeVelocity.dot(normal);

    if (velocityAlongNormal > 0) return;

    float j = -(1.0f + restitution) * velocityAlongNormal;
    j /= (1.0f / a->mass + 1.0f / b->mass);

    Vec2 impulse = normal * j;

    a->velocity -= impulse * (1.0f / a->mass);
    b->velocity += impulse * (1.0f / b->mass);
}