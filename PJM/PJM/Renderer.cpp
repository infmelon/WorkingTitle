#include "Renderer.h"
#include "Config.h"

Renderer::Renderer(SDL_Window * window)
{
	if (window == nullptr)
	{
		throw "Windowargument darf nicht NUll sein";
	}

	this->window = window;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderClear(renderer);

	Config::gui->draw(this);

	SDL_RenderPresent(renderer);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer * Renderer::getRenderer()
{
	return this->renderer;
}
