#pragma once

#include "GUIElement.h"
#include <string>

class GUIButton : public GUIElement
{
private:
	std::string text;

public:
	GUIButton();
	GUIButton(std::string text, int xPos, int yPos, int width, int height);

	void draw(Renderer* renderer);
};