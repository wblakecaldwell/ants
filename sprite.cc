#include <SDL2/SDL.h>
#include "sprite.h"
#include "draw.h"

// Constructor
Sprite::Sprite() {
  // Initialize member variables here
}

// Destructor
Sprite::~Sprite() {
  // Release any resources if needed
}

// Copy constructor
Sprite::Sprite(const Sprite& other) {
  // Copy member variables from other object
}

// Assignment operator
Sprite& Sprite::operator=(const Sprite& other) {
  if (this != &other) {
    // Copy member variables from other object
  }
  return *this;
}

void Sprite::DrawRect(SDL_Renderer* renderer, Point topLeft, Point bottomRight) {
  // for (int x = topLeft.x; x <= bottomRight.x; ++x) {
  //   for (int y = topLeft.y; y <= bottomRight.y; ++y) {
  //     Uint8 r = rand() % 256;
  //     Uint8 g = rand() % 256;
  //     Uint8 b = rand() % 256;
  //     SDL_SetRenderDrawColor(renderer, Uint8(255), Uint8(0), Uint8(0), Uint8(255));
  //     SDL_RenderDrawPoint(renderer, x, y);
  //   }
  // }
  // SDL_SetRenderDrawColor(renderer, Uint8(255), Uint8(0), Uint8(0), Uint8(255));
  // SDL_Rect rect = { topLeft.x, topLeft.y, bottomRight.x-topLeft.x, bottomRight.y-topLeft.y };
  // SDL_RenderDrawRect(renderer, &rect);

// Create a rectangle
SDL_Rect rect = { topLeft.x, topLeft.y, bottomRight.x-topLeft.x, bottomRight.y-topLeft.y };
SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 255);
SDL_RenderFillRect(renderer, &rect);
}