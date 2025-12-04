#pragma once

class Vec2 {

    public:

        float x, y;

        Vec2();
        Vec2(float x, float y);

        
        Vec2 operator/(const float scalar) const;
        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(float scalar) const;
        Vec2& operator-=(const Vec2& other);
        Vec2& operator+=(const Vec2& other);

        float length() const;
        Vec2 normalize() const; 
        float dot(const Vec2& other) const;
};