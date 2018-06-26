#include "EventHandler.h"
#include "InputWrapper.h"

EventHandler::EventHandler()
{

}

/*
Funktion behandelt jedes Event mithilfe des Eventhandlers.

Hier wird abgefragt um welches Event es sich handelt um damit
die passende Funktion des EventHandlers aufzurufen.
*/
void EventHandler::handleEvent()
{
	InputWrapper::updateEvents();

	if (InputWrapper::isButtonDownNow(SDL_SCANCODE_ESCAPE) ||InputWrapper::getQuit())
	{
		Config::quit = true;
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
