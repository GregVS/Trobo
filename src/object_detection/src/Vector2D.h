//
// Created by greg on 11/30/18.
//

#ifndef PROJECT_VECTOR2D_H
#define PROJECT_VECTOR2D_H

#include <cmath>
#include <iostream>

template <typename T> class Vector2D
{
private:
    T x;
    T y;

public:
    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
    virtual ~Vector2D() = default;

    // Accessors
    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    // Vector arithmetic
    inline Vector2D<T> operator-() const
    { return Vector2D<T>(-x, -y); }

    inline Vector2D<T> operator+() const
    { return Vector2D<T>(+x, +y); }

    inline Vector2D<T> operator+(const Vector2D<T>& v) const
    { return Vector2D<T>(x+v.x, y+v.y); }

    inline Vector2D<T> operator-(const Vector2D<T>& v) const
    { return Vector2D<T>(x-v.x, y-v.y); }

    inline Vector2D<T> operator*(const T& s) const
    { return Vector2D<T>(x*s, y*s); }

    // Dot product
    inline T operator*(const Vector2D<T>& v) const
    { return x*v.x + y*v.y; }

    // l-2 norm
    inline T norm() const { return sqrt(x*x + y*y); }

    // inner angle (radians)
    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};

#endif //PROJECT_VECTOR2D_H
