#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

#endif // UTILITY_H_INCLUDED
