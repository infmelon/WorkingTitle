#pragma once

#include <SDL.h>
#include "EventHandler.h"

class Core
{
private:
	SDL_Window * window;
	Renderer * renderer;
	EventHandler * eventHandler;

public:
	Core();
	void startLoop();

	static bool quit;
};