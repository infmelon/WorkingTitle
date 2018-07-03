#pragma once

#include <string>
#include <SDL_ttf.h>

class Fonts
{
private:
	static std::string fontPath;
	static std::string font;

public:
	static SDL_Texture * createFont(std::string text, int size, SDL_Color color, SDL_Renderer * renderer);
	static void setFont(std::string text);

};