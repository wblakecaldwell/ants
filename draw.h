#ifndef DRAW_H
#define DRAW_H

#include <cstdint>
#include <SDL.h>
#include <iostream>

class Vector {
public:
    int x;
    int y;

    Vector(int xValue, int yValue) : x(xValue), y(yValue) {}

    bool operator==(const Vector& other) const {
        return (x == other.x) && (y == other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}

    bool Inside(Point topLeft, Point bottomRight);
    void Move(Vector vector);

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << int(point.x) << "," << int(point.y) << ")";
        return os;
    }
};

#endif // DRAW_H
