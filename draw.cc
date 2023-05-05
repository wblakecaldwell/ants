#include "draw.h"

bool Point::Inside(Point topLeft, Point bottomRight) {
  return x >= topLeft.x && x <= bottomRight.x && y >= topLeft.y && y <= bottomRight.y;
}

void Point::Move(Vector vector) {
  x += vector.x;
  y += vector.y;
}
