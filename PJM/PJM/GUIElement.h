#pragma once

#include <SDL.h>
#include "Renderer.h"
#include "InputWrapper.h"

struct GUIRect
{
	int xPos;
	int yPos;
	int width;
	int height;
	
	bool clicked()
	{
		bool ret = true;

		if (InputWrapper::isMouseButtonDownNow(SDL_BUTTON_LEFT))
		{
			int mouseX = InputWrapper::getMouseX();
			int mouseY = InputWrapper::getMouseY();

			if (!((mouseX>xPos)&&(mouseX<(xPos+width))&&(mouseY>yPos)&&(mouseY<(yPos+height))))
			{
				ret = false;
			}
		}
		else
		{
			ret = false;
		}

		return ret;
	}

	bool hovered()
	{
		int mouseX = InputWrapper::getMouseX();
		int mouseY = InputWrapper::getMouseY();

		return ((mouseX > xPos) && (mouseX < (xPos + width)) && (mouseY > yPos) && (mouseY < (yPos + height)));
	}
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