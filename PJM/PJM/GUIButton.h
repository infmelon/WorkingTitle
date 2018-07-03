#pragma once

#include "GUIElement.h"
#include <string>

class GUIButton : public GUIElement
{
private:
	std::string text;

public:
	GUIButton(const std::string &text, const GUIRect &guiRect);
	GUIButton(const std::string &text, int xPos, int yPos, int width, int height);

	void draw(Renderer* renderer);
};