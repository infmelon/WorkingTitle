#pragma once

#include <SDL.h>
#include "Renderer.h"

struct GUIRect
{
	int xPos;
	int yPos;
	int width;
	int height;
	bool clicked;
};

class GUIElement
{
protected: 
	GUIRect guiRect;

public:
	GUIElement()
	{
		;
	};
	GUIElement(int xPos, int yPos, int width, int height);
	void update();

	//Erzeugt ein neues Rechteck welches vom Renderer gezeichnet wird;
	virtual void draw(Renderer* renderer) = 0;
};