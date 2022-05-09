#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

class application
{
private:
    bool running;
    //static SDL_Event gEvent;

public:
    application();
    ~application();
    void update();
};

#endif // APPLICATION_H_INCLUDED
