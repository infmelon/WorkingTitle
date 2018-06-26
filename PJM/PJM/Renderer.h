#pragma once

#include <SDL.h>

class Config;

class Renderer
{
private:
	SDL_Renderer * renderer;
	SDL_Window * window;

public:
	explicit Renderer(SDL_Window * window);
	SDL_Renderer* getRenderer();
	void render();
	~Renderer();
};