#include "Fonts.h"

std::string Fonts::fontPath = "C:\\Windows\\Fonts\\";
std::string Fonts::font = "ARIALN.TTF";

SDL_Texture * Fonts::createFont(std::string text, int size, SDL_Color color, SDL_Renderer * renderer)
{
	TTF_Font * fontObject = TTF_OpenFont((fontPath + font).c_str(), size);
	if (fontObject == NULL)
	{
		TTF_CloseFont(fontObject);
		throw "Schrift konnte nicht geladen werden.";
	}

	SDL_Surface * surface = TTF_RenderText_Solid(fontObject, text.c_str(), color);
	if (surface == NULL)
	{
		TTF_CloseFont(fontObject);
		SDL_FreeSurface(surface);
		throw "Fehler beim erstellen der Schrift.";
	}

	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		TTF_CloseFont(fontObject);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
		throw "Fehler beim erstellen der Schrift.";
	}

	SDL_FreeSurface(surface);
	TTF_CloseFont(fontObject);

	return texture;
}

void Fonts::setFont(std::string text)
{
	font = text;
}
