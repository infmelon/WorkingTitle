#pragma once

#include "GUI.h"


class Config
{
public: 
	Config();
	GUI* gui;
//	Map* map;
	~Config();

	static int menueXPos;
	static int menueYPos;
};