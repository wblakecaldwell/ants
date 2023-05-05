#include <SDL2/SDL.h>
#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ctime>

#include "absl/strings/str_cat.h"
#include "absl/synchronization/mutex.h"
#include "sprite.h"
#include "ant.h"

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

  Point windowTopLeft = Point(0,0);
  Point windowBottomRight = Point(WINDOW_WIDTH, WINDOW_HEIGHT);
  std::cout << "Window top left: " << windowTopLeft << ", bottom right: " << windowBottomRight << std::endl;

  int step = 3;
  Vector vector = Vector(step,step);
  Point topLeft = Point(3, 50);
  Point bottomRight = Point(43, 90);

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Ant ant = Ant("../sprites/red-ant.jpg", 100, 100, renderer);
    ant.render(renderer);

    while(true) {

      Point newTopLeft = topLeft;
      Point newBottomRight = bottomRight;

      newTopLeft.Move(vector);
      newBottomRight.Move(vector);

      if(!newTopLeft.Inside(windowTopLeft, windowBottomRight) || 
        !newBottomRight.Inside(windowTopLeft, windowBottomRight)) {
          std::cout << "Out of bounds at topLeft: " << topLeft << ", bottomRight: " << bottomRight 
            << " on window " << windowTopLeft << ", " << windowBottomRight << std::endl;

          // need to change direction
          int random_num = (std::rand() % 4) + 1;
          switch (random_num) {
              case 1:
                  vector = Vector(step, -step);
                  break;
              case 2:
                  vector = Vector(-step, -step);
                  break;
              case 3:
                  vector = Vector(step, step);
                  break;
              case 4:
                  vector = Vector(-step, step);
                  break;
              default:
                  std::cout << "Number not in range" << std::endl;
                  return -1;
                  break;
          }

          newTopLeft = topLeft;
          newBottomRight = bottomRight;
          newTopLeft.Move(vector);
          newBottomRight.Move(vector);
          continue;
      }
      topLeft = newTopLeft;
      bottomRight = newBottomRight;
      break;
    };

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
