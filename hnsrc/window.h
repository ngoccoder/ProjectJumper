#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#pragma once
#include "SDL.h"
#include "utility.h"

class window
{
public:
    window();
    ~window();

    void setRect(const int &x, const int &y)
    {
        rect_.x = x;
        rect_.y = y;
        rect_.w = width;
        rect_.h = height;
    }

    SDL_Rect getRect()
    {
        return rect_;
    }

    SDL_Texture* getTexture()
    {
        return object_;
    }

    bool loadImage(std::string path, SDL_Renderer* screen);
    void render(SDL_Renderer* des, SDL_Rect* clip = NULL);
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    void setAlpha(Uint8 alpha);
    void free();

public:
    SDL_Texture* object_;
    SDL_Rect rect_;
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
};


#endif // WINDOW_H_INCLUDED
