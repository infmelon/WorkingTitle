#include "Config.h"

int Config::menueXPos = 0;
int Config::menueYPos = 0;
bool Config::quit = false;
GUI* Config::gui = nullptr;

void Config::init()
{
	gui = new GUI();
}
