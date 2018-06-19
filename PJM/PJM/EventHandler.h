#pragma once

#include <SDL.h>
#include "Config.h"

class EventHandler
{
private:
	bool keyPressed[285];
	bool mousePressed[4]; // Mousebuttons fangen bei 1 an
	Config config;	// Benötigt um die richtigen events auszulösen
					// Beispiel ist der Klick auf dem Menü oder dem Bildschirm

	void handleKeyEvent();
	void handleMouseEvent();

public:
	EventHandler(Config &config);
	void handleEvent(SDL_Event * event, bool &quit);//test
};