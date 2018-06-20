#include "GUIElement.h"

/*
Konstruktor initialisert die Größe des GuiElements
*/
GUIElement::GUIElement(int xPos, int yPos, int width, int height)
{
	if (xPos < 0)
	{
		throw "Ungültige Position X";
	}
	if (yPos < 0)
	{
		throw "Ungültige Position Y";
	}
	if (width <= 0)
	{
		throw "Ungültige Breite";
	}
	if (height <= 0)
	{
		throw "Ungültige Höhe";
	}

	this->guiRect.xPos = xPos;
	this->guiRect.yPos = yPos;
	this->guiRect.width = width;
	this->guiRect.height = height;
}

void GUIElement::update()
{

}
