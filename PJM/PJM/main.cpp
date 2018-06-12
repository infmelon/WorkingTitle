/*
* main.cpp
*
*  Created on: 12.06.2018
*      Author: Sven
*/

#include <SDL.h>
#include <iostream>

int wmain(int argc, char* args[])
{
	bool quit = false;
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Die SDL konnte nicht initalisiert werden (" << SDL_GetError() << ")" << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);

	std::cout << "Willkommen zum SDL Testprogramm." << std::endl;

	SDL_Event* event = new SDL_Event();
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while (!quit)
	{
		long frameTime = SDL_GetTicks();
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_QUIT)
			{
				quit = true;
			}
			if (event->type == SDL_KEYDOWN)
			{
				switch (event->key.keysym.sym)
				{
				case SDLK_ESCAPE:
					std::cout << "Escape pressed" << std::endl;
					quit = true;
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		if (SDL_GetTicks() - frameTime < 30) {
			SDL_Delay(30 - (SDL_GetTicks() - frameTime));
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit(); // Herunterfahren der SDL Bibliotheken
	return 0;
}


