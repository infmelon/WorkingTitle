#include "Config.h"

int Config::menueXPos = 0;
int Config::menueYPos = 0;

Config::Config()
{
	this->gui = new GUI();
}

Config::~Config()
{
	delete this->gui;
}
