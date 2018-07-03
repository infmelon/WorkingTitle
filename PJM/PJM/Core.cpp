#include "Core.h"
#include "InputWrapper.h"
#include <SDL_ttf.h>

/*
Initialisiert alle wichtigen Variablen.
*/
Core::Core()
{
	eventHandler = new EventHandler();
	Config::init();
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
	if (TTF_Init() != 0)
	{
		throw "TTF konnte nicht initialisiert werden";
	}

	// TODO: Daten aus der Konfig lesen.
	window = SDL_CreateWindow("PJM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		400, 400, SDL_WINDOW_SHOWN);
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

	renderer = new Renderer(window);

	while (!Config::quit)
	{
		long frameTime = SDL_GetTicks();
		
		eventHandler->handleEvent();

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