#pragma once
#include "Shape.h"

class Circle : public Shape{

    public:

        float radius;

        Circle(float radius);

        ShapeType get_type() const override;    
    
};