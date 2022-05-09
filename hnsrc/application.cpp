#include "application.h"

application::application()
{
    while(running) {
		while(SDL_PollEvent(&gEvent))
        {
	    	if(gEvent.type == SDL_QUIT)
	    	{
	     		running = false;
	    	}
			if(gEvent.type == SDL_KEYDOWN)
			{

			}
		}
		update();
		SDL_Delay(12);
	}
}

application::~application()
{

}

application::update(SDL_Rect bg)
{
    SDL_SetTextureColorMod( gBackground.object_, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(gScreen);

    SDL_Rect* clip = &bg;

    gBackground.setColor(0, 255, 255);
    gBackground.render(gScreen, clip);

    SDL_RenderPresent(gScreen);
}
