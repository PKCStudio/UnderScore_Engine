#include "USWindow.h"

namespace UnderScore::Engine::Window
{
	NSGLWindow UnderScore::Engine::Window::USWindow_CreateOpenGLWindow(const char* title, int w, int h)
	{
		// Create an SDL window that supports Vulkan rendering.
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "Could not initialize SDL." << std::endl;
			throw; //TODO: Fix that
		}

		Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE; //TODO load this from File

		SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, windowFlags);
		if (window == NULL) {
			std::cout << "Could not create SDL window." << std::endl;
			throw; //TODO: Fix that
		}

		SDL_SetWindowIcon(window, USWindow_LoadSDLIcon("Assets/USIcon.png"));

		SDL_GLContext context = SDL_GL_CreateContext(window);

		UnderScore::Engine::Logger::USLogger::GetInstance().logDebug("Tedst");
		return NSGLWindow(window, context);
	}

	SDL_Surface* USWindow_LoadSDLIcon(const char* iconPath)
	{
		return IMG_Load(iconPath);
	}

	NSGLWindow::NSGLWindow(SDL_Window* wnd, SDL_GLContext cnt)
	{
		this->glContext = cnt;
		this->window = wnd;
	}
}