#pragma once

#include <SDL.h>

class Renderer
{
private:
	SDL_Renderer * renderer;
	SDL_Window * window;

public:
	explicit Renderer(SDL_Window * window);
	void render();
	~Renderer();
};