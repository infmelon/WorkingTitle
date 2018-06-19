#include "EventHandler.h"

EventHandler::EventHandler(Config & config)
{
	this->config = config;
}

/*
Funktion behandelt jedes Event mithilfe des Eventhandlers.

Hier wird abgefragt um welches Event es sich handelt um damit
die passende Funktion des EventHandlers aufzurufen.
*/
void EventHandler::handleEvent(SDL_Event* event, bool &quit)
{
	SDL_PollEvent(event);

	switch (event->type)
	{
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_KEYDOWN:
		keyPressed[event->key.keysym.scancode] = true;
		break;
	case SDL_KEYUP:
		keyPressed[event->key.keysym.scancode] = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		mousePressed[event->button.button] = true;
		break;
	case SDL_MOUSEBUTTONUP:
		mousePressed[event->button.button] = false;
		break;
	}

	handleKeyEvent();
	handleMouseEvent();
}

/*
Handelt alle KeyEvents
*/
void EventHandler::handleKeyEvent()
{
	//TODO Scancode nachfragen und dementsprechend funktion ausführen
}

/*
Handelt alle MouseEvents
*/
void EventHandler::handleMouseEvent()
{
	if (mousePressed[SDL_BUTTON_LEFT])
	{
		//TODO
	}
	if (mousePressed[SDL_BUTTON_RIGHT])
	{
		//TODO
	}
}
