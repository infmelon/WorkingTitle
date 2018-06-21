#include "GUIButton.h"

GUIButton::GUIButton()
{
}

GUIButton::GUIButton(std::string text, int xPos, int yPos, int width, int height)
	: GUIElement(xPos, yPos, width, height)
{
	this->text = text;
}

void GUIButton::draw(Renderer * renderer)
{
	SDL_Rect rect;
	rect.x = this->guiRect.xPos;
	rect.y = this->guiRect.yPos;
	rect.w = this->guiRect.width;
	rect.h = this->guiRect.height;

	SDL_SetRenderDrawColor(renderer->getRenderer(), 144, 0, 133, 0);
	SDL_RenderFillRect(renderer->getRenderer(), &rect);
}
