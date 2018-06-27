#pragma once

#include "GUI.h"


class Config
{
public: 
	//Verhindert das Instanziieren der Utitlity-Klasse:
	Config() = delete;

	static void init();
	static GUI* gui;
//	Map* map;

	static int menueXPos;
	static int menueYPos;

	static bool quit;
};