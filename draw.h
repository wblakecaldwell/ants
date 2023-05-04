#ifndef DRAW_H
#define DRAW_H

class Point {
public:
    Point(Uint8 x, Uint8 y) : x_(x), y_(y) {}

    Uint8 x() const { return x_; }
    Uint8 y() const { return y_; }

    void set_x(Uint8 x) { x_ = x; }
    void set_y(Uint8 y) { y_ = y; }

private:
    Uint8 x_;
    Uint8 y_;
};

#endif // DRAW_H
