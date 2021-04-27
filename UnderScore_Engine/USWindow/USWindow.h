#include <SDL2/SDL.h>
#include <iostream>
#include <SDL_Image/include/SDL_image.h>

#include "../USLogger/USLogger.h"

#ifndef NSGLWindow_HEADER
#define NSGLWindow_HEADER

namespace UnderScore::Engine::Window
{

	class NSGLWindow
	{
	public: 
		SDL_Window* window;
		SDL_GLContext glContext;

		NSGLWindow(SDL_Window* wnd, SDL_GLContext cnt);
	};

	extern NSGLWindow USWindow_CreateOpenGLWindow(const char* title, int w, int h);

	extern SDL_Surface* USWindow_LoadSDLIcon(const char* iconPath);
}
#endif