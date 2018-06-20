#pragma once

#include "GUIElement.h"

class GUI
{
private:
	int xPos;
	int yPos;

	GUIElement* elements[12];
	void init();

public:
	GUI();
	void update();
	void draw(Renderer* renderer);
};