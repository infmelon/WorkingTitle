#include "GUI.h"
#include "GUIButton.h"
#include "Config.h"

GUI::GUI()
{
	this->xPos = Config::menueXPos;
	this->yPos = Config::menueYPos;

	this->init();
}

void GUI::init()
{
	GUIElement* element1 = new GUIButton("test", xPos + 20, yPos + 10, 100, 100);
	this->elements[1] = element1;
}

void GUI::update()
{
}

void GUI::draw(Renderer * renderer)
{
	this->elements[1]->draw(renderer);
}
