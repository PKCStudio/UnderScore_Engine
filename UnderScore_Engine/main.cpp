// Tell SDL not to mess with main()
#define SDL_MAIN_HANDLED

#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include <gl/GL.h>

#include <iostream>
#include <vector>
#include "USWindow/USWindow.h"

int main()
{
    UnderScore::Engine::Window::NSGLWindow nsWindow = UnderScore::Engine::Window::USWindow_CreateOpenGLWindow("Test", 1920, 1080);

    bool stillRunning = true;
    while(stillRunning) {

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            
            switch(event.type) {

            case SDL_QUIT:
                stillRunning = false;
                break;
                
            default:
                // Do nothing.
                break;
            }

            glClearColor(1.f, 0.f, 1.f, 0.f);
            glClear(GL_COLOR_BUFFER_BIT);


            SDL_GL_SwapWindow(nsWindow.window);
        }

        SDL_Delay(10);
    }

    // Clean up.
    SDL_DestroyWindow(nsWindow.window);
    SDL_Quit();

    return 0;
}
