#include <cmath>
#include "Vec2.h"

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}


Vec2 Vec2::operator+(const Vec2& other) const {

    return Vec2(x + other.x, y + other.y);

}   

Vec2 Vec2::operator-(const Vec2& other) const {

    return Vec2(x - other.x, y - other.y);

}

Vec2 Vec2::operator/(const float scalar) const {

    if (scalar == 0) return Vec2(0, 0);
    return Vec2(x / scalar, y / scalar);

}

Vec2 Vec2::operator*(float scalar) const {

    return Vec2(x * scalar, y * scalar);

}

float Vec2::length() const {

    return sqrt(x * x + y * y);

}

Vec2 Vec2::normalize() const {

    float len = length();
    if (len == 0) return Vec2(0, 0); 
    return Vec2(x / len, y / len);

}

float Vec2::dot(const Vec2& other) const {

    return x * other.x + y * other.y;

}

Vec2& Vec2::operator-=(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator+=(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}