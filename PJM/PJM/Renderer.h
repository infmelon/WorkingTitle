#pragma once

#include <SDL.h>

class Config;

class Renderer
{
private:
	SDL_Renderer * renderer;
	SDL_Window * window;
	Config * config;

public:
	explicit Renderer(SDL_Window * window, Config * config);
	SDL_Renderer* getRenderer();
	void render();
	~Renderer();
};