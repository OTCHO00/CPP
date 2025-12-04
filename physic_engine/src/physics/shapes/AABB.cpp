#include "AABB.h"

AABB::AABB(Vec2 min, Vec2 max) : min(min), max(max) {}

Shape::ShapeType AABB::get_type() const {

    return ShapeType::AABB;

}