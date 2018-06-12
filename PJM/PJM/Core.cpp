#include "Core.h"

/*
Funktion startet das Spiel. Spiel läuft eine Schleife durch die alle
Events abfängt und vearbeitet.
*/
void Core::startLoop()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw "SDL konnte nicht initialisiert werden";
	}

	// TODO: Daten aus der Konfig lesen.
	window = SDL_CreateWindow("PJM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		400, 400, SDL_WINDOW_SHOWN);

	eventHandler = new EventHandler();
	renderer = new Renderer(window);
	event = new SDL_Event();

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
					quit = true;
					break;
				}
			}

			eventHandler->handleEvent(event);
		}

		renderer->render();

		// Delay setzen damit die FPS runtergesetzt werden.
		if (SDL_GetTicks() - frameTime < 30) {
			SDL_Delay(30 - (SDL_GetTicks() - frameTime));
		}
	}

	delete renderer;
	delete eventHandler;
	SDL_DestroyWindow(window);
	SDL_Quit(); // Herunterfahren der SDL Bibliotheken
}