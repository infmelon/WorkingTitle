#include "Core.h"

/*
Initialisiert alle wichtigen Variablen.
*/
Core::Core()
{
	this->config = Config();

	eventHandler = new EventHandler(config);
	event = new SDL_Event();
}

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

	renderer = new Renderer(window);

	while (!quit)
	{
		long frameTime = SDL_GetTicks();
		
		eventHandler->handleEvent(event, quit);

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