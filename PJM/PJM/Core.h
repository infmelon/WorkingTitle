#pragma once

#include <SDL.h>
#include "EventHandler.h"

class Core
{
private:
	SDL_Window * window;
	Renderer * renderer;
	EventHandler * eventHandler;
	Config * config;
	
	SDL_Event * event;
	bool quit = false;

public:
	Core();
	void startLoop();
};