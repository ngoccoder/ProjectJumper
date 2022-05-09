#include <iostream>
#include "utility.h"
#include "window.h"
#include "render.h"
//#include "application.h"

using namespace std;

window gBackground;
window gGround;
window gLine;
window gObject;
SDL_Rect ob;
SDL_Rect gr;
SDL_Rect bg;

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) success = false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    gWindow = SDL_CreateWindow("Jumper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) success = false;
    else
    {
        gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gScreen == NULL) success = false;
        else
        {
            SDL_SetRenderDrawColor(gScreen, 0, 0, 0xFF, 0xFF);
            int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					success = false;
				}
        }
    }
    return success;
}

bool load()
{
    bool flag = gBackground.loadImage("image/bg01.png", gScreen);
    bool flag2 = gGround.loadImage("image/ground01.png", gScreen);
    bool flag3 = gLine.loadImage("image/line.png", gScreen);
    bool flag4 = gObject.loadImage("image/spikes.png", gScreen);
    if (flag == false || flag2 == false) return false;
    else
    {
        bg.x = 0;
        bg.y = 448;
        bg.w = 1024;
        bg.h = 576;

        ob.x = 0;
        ob.y = 0;
        ob.w = 42;
        ob.h = 42;

        gr.x = 0;
        gr.y = 0;
        gr.w = 256;
        gr.h = 256;
    }
    return true;
}

void close()
{
    gBackground.free();
    gGround.free();
    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (!init()) return -1;
    if (!load()) return -2;

    bool quit = false;
    while (!quit)
    {
        while(SDL_PollEvent(&gEvent) != 0)
        {
            if (gEvent.type == SDL_QUIT) quit = true;
        }
        //Render texture to screen
        SDL_SetTextureColorMod( gBackground.object_, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(gScreen);

        SDL_Rect* clip = &bg;
        gBackground.setColor(0, 0, 255);
        gBackground.setAlpha(255);
        gBackground.rect_.x += 1;
        if (gBackground.rect_.x >= 1024) gBackground.rect_.x = 0;
        gBackground.render(gScreen, clip);
        gBackground.rect_.x -= 1024;
        gBackground.render(gScreen, clip);
        gBackground.rect_.x += 1024;

        SDL_Rect* clip2 = &gr;
        gGround.setAlpha(255);
        gGround.rect_.y = 432;
        gGround.rect_.w = 216;
        gGround.rect_.h = 216;
        gGround.rect_.x -= 4;
        if (gGround.rect_.x <= -216) gGround.rect_.x = 0;
        for (int i = 0; i < 6; i++)
        {
            gGround.render(gScreen, clip2);
            gGround.rect_.x += 216;
        }
        gGround.rect_.x -= 1296;

        SDL_Rect* clip3 = &ob;
        gObject.rect_.x = 512;
        gObject.rect_.y = 390;
        gObject.rect_.w = 42;
        gObject.rect_.h = 42;
        gObject.render(gScreen, clip3);

        gLine.rect_.x = 0;
        gLine.rect_.y = 431;
        gLine.rect_.w = 1024;
        gLine.rect_.h = 2;
        gLine.render(gScreen, NULL);

        SDL_RenderPresent(gScreen);
        SDL_Delay(16);
    }
    close();
    return 0;
}
