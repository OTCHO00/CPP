#include "Circle.h"

Circle::Circle(float radius) : radius(radius) {}

Shape::ShapeType Circle::get_type() const {

    return ShapeType::CIRCLE;

}