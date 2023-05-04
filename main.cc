#include <SDL2/SDL.h>
#include <stdio.h>

#include <cstdlib>
#include <ctime>

#include "absl/strings/str_cat.h"
#include "absl/synchronization/mutex.h"
#include "sprite.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char *argv[]) {
  srand(static_cast<unsigned>(time(0)));

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Random Pixels", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!window) {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Event event;
  bool running = true;

  Point topLeft = Point(Uint8(100), Uint8(100));
  Point bottomRight = Point(Uint8(200), Uint8(400));

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    topLeft.set_x(topLeft.x()+1);
    topLeft.set_y(topLeft.y()+1);

    bottomRight.set_x(bottomRight.x()+1);
    bottomRight.set_y(bottomRight.y()+1);

    Sprite s = Sprite();
    s.DrawRect(renderer, topLeft, bottomRight);

    // Update the screen
    SDL_RenderPresent(renderer);
    SDL_Delay(1000 / 24);  // Delay for 1/24th of a second
  }

  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
