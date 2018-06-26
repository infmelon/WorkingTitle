#pragma once

#include <SDL.h>
#include "Config.h"

class EventHandler
{
private:
	bool keyPressed[285] = { 0 }; // Arrays mit 0 initialisieren
	bool mousePressed[4] = { 0 }; // Mousebuttons fangen bei 1 an

	void handleKeyEvent();
	void handleMouseEvent();

public:
	EventHandler();
	void handleEvent();//test
};