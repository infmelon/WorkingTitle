#pragma once

#include <SDL.h>
#include "Config.h"

class EventHandler
{
private:
	bool keyPressed[285];
	bool mousePressed[4]; // Mousebuttons fangen bei 1 an
	Config config;	// Ben�tigt um die richtigen events auszul�sen
					// Beispiel ist der Klick auf dem Men� oder dem Bildschirm

	void handleKeyEvent();
	void handleMouseEvent();

public:
	EventHandler(Config &config);
	void handleEvent(SDL_Event * event, bool &quit);//test
};