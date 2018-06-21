#pragma once

enum class ButtonState
{
	UP,
	UP_NOW,
	DOWN,
	DOWN_NOW
};

class InputWrapper
{
public:
	//Initialisiert die Felder usw.
	static void initialize();
	static bool is_initialized();

	//Aktualisiert die Inhalte mithilfe der aktuellen SDL-Events
	static void updateEvents();

	//Abruf der Position der Maus:
	static int getMouseX();
	static int getMouseY();

	//Abruf der Maus-Tastenzustände:
	static bool isMouseButtonUp(int key);
	static bool isMouseButtonUpNow(int key);
	static bool isMouseButtonDown(int key);
	static bool isMouseButtonDownNow(int key);
	static ButtonState getMouseButtonState(int key);

	//Abruf der Tastatur-Tastenzustände:
	static bool isButtonUp(int key);
	static bool isButtonUpNow(int key);
	static bool isButtonDown(int key);
	static bool isButtonDownNow(int key);
	static ButtonState getButtonState(int key);

	//Sonder-Events:
	static bool getQuit();

private:
	static ButtonState keyStates[285];
	static ButtonState mouseStates[2];
	static int mouseX;
	static int mouseY;

	static bool quit;

	static bool initialized;
};
//Name:				InputWrapper
//Funktionalität:	Wrapped die SDL_EVENT-Funktionalität als Utility-Klasse

