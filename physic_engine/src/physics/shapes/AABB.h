#pragma once
#include "Shape.h"
#include "../math/Vec2.h"

class AABB : public Shape {

    public:

        Vec2 min, max;

        AABB(Vec2 min, Vec2 max);

        ShapeType get_type() const override;

};