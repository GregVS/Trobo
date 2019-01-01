//
// Created by greg on 11/30/18.
//

#ifndef PROJECT_VECTOR2D_H
#define PROJECT_VECTOR2D_H

#include <cmath>
#include <iostream>

template <typename T> class vector_2d
{
private:
    T x;
    T y;

public:
    explicit vector_2d(const T& x=0, const T& y=0) : x(x), y(y) {}
    vector_2d(const vector_2d<T>& src) : x(src.x), y(src.y) {}
    virtual ~vector_2d() = default;

    // Accessors
    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    // Vector arithmetic
    inline vector_2d<T> operator-() const
    { return vector_2d<T>(-x, -y); }

    inline vector_2d<T> operator+() const
    { return vector_2d<T>(+x, +y); }

    inline vector_2d<T> operator+(const vector_2d<T>& v) const
    { return vector_2d<T>(x+v.x, y+v.y); }

    inline vector_2d<T> operator-(const vector_2d<T>& v) const
    { return vector_2d<T>(x-v.x, y-v.y); }

    inline vector_2d<T> operator*(const T& s) const
    { return vector_2d<T>(x*s, y*s); }

    // Dot product
    inline T operator*(const vector_2d<T>& v) const
    { return x*v.x + y*v.y; }

    // l-2 norm
    inline T norm() const { return sqrt(x*x + y*y); }

    // inner angle (radians)
    static T angle(const vector_2d<T>& v1, const vector_2d<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};

#endif //PROJECT_VECTOR2D_H
