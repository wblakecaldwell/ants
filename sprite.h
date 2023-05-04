#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include "draw.h"

class Sprite {
 public:
  // Constructor
  Sprite();

  // Destructor
  ~Sprite();

  // Copy constructor
  Sprite(const Sprite &other);

  // Assignment operator
  Sprite &operator=(const Sprite &other);

  void DrawRect(SDL_Renderer *renderer, Point topLeft, Point bottomRight);

 private:
  // Add private member variables here
};

#endif  // SPRITE_H
