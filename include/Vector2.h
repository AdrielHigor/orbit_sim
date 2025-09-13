#pragma once

class Vector2 {
    private:
        float x;
        float y;
   
        public:
        Vector2();               
        Vector2(float x, float y);
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;

        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);

        Vector2 normalized() const;
        float magnitude() const;
};