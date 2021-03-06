#include "GUIButton.h"
#include "Fonts.h"

GUIButton::GUIButton(const std::string &text, const GUIRect & guiRect)
	: GUIElement(guiRect)
{
	this->text = text;
}

GUIButton::GUIButton(const std::string &text, int xPos, int yPos, int width, int height)
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

	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Texture * texture = Fonts::createFont(text, 80, color, renderer->getRenderer());

	SDL_RenderCopy(renderer->getRenderer(), texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}
