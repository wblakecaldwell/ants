#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "ant.h"
#include <string>

Ant::Ant(const std::string& texturePath, int x, int y, SDL_Renderer* renderer)
    : x_(x), y_(y) {
    // Load the ant sprite texture
    SDL_Surface* surface = IMG_Load(texturePath.c_str());
    if (!surface) {
        printf("IMG_Load: %s\n", IMG_GetError());
    } else {
        // Set the white color (255, 255, 255) as transparent
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));

        texture_ = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture_) {
            printf("SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
        } else {
            width_ = surface->w;
            height_ = surface->h;
        }
        SDL_FreeSurface(surface);
    }
}

Ant::~Ant() {
    if (texture_) {
        SDL_DestroyTexture(texture_);
    }
}

void Ant::update() {
    // Implement ant logic updates here
}

void Ant::render(SDL_Renderer* renderer) {
    if (texture_) {
        SDL_Rect dstRect = {x_, y_, 50, 50};
        SDL_RenderCopy(renderer, texture_, nullptr, &dstRect);
    }
}