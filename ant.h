#ifndef ANT_H
#define ANT_H

#include <SDL2/SDL.h>
#include <string>

class Ant {
public:
    Ant(const std::string& texturePath, int x, int y, SDL_Renderer* renderer);
    ~Ant();
    void update();
    void render(SDL_Renderer* renderer);
    int getX() const { return x_; }
    int getY() const { return y_; }

private:
    SDL_Texture* texture_;
    int x_, y_;
    int width_, height_;
};

#endif // ANT_H