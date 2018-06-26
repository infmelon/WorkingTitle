#pragma once

#include "GUI.h"


class Config
{
public: 
	static void init();
	static GUI* gui;
//	Map* map;

	static int menueXPos;
	static int menueYPos;

	static bool quit;
};