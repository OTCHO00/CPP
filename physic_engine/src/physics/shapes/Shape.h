#pragma once

class Shape {

    public:
    
        enum ShapeType {
            CIRCLE,
            AABB
        };
        
        virtual ShapeType get_type() const = 0;

        virtual ~Shape() = default;

}; 