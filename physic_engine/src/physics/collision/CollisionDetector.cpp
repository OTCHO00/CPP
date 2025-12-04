#include "shapes/Circle.h"
#include "CollisionDetector.h"

bool CollisionDetector::CheckCollision_CircleCircle(RigidBody* a, RigidBody* b) {

    Circle* circle_a = static_cast<Circle*>(a->shape);
    float radius_a = circle_a->radius;

    Circle* circle_b = static_cast<Circle*>(b->shape);
    float radius_b = circle_b->radius;

    float sum_radius = radius_a + radius_b;
    Vec2 diff = a->position - b->position;
    float distance = diff.length();

    return distance < sum_radius;
}