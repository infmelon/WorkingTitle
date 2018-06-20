#include "GUIElement.h"

/*
Konstruktor initialisert die Gr��e des GuiElements
*/
GUIElement::GUIElement(int xPos, int yPos, int width, int height)
{
	if (xPos < 0)
	{
		throw "Ung�ltige Position X";
	}
	if (yPos < 0)
	{
		throw "Ung�ltige Position Y";
	}
	if (width <= 0)
	{
		throw "Ung�ltige Breite";
	}
	if (height <= 0)
	{
		throw "Ung�ltige H�he";
	}

	this->guiRect.xPos = xPos;
	this->guiRect.yPos = yPos;
	this->guiRect.width = width;
	this->guiRect.height = height;
}

void GUIElement::update()
{

}
