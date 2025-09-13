#include "Vector2.h"
#include <cmath>

Vector2::Vector2() {
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector2::getX() const {
    return x;
}

float Vector2::getY() const {
    return y;
}

void Vector2::setX(float x) {
    this->x = x;
}

void Vector2::setY(float y) {
    this->y = y;
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
    return Vector2(x / scalar, y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

Vector2 Vector2::normalized() const {
    float magnitude = std::sqrt(x * x + y * y);
    return Vector2(x / magnitude, y / magnitude);
}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}