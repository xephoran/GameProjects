#pragma once
#include<SFML/Graphics.hpp>
class OptionsMenu
{
public:
	OptionsMenu();
	int runOptionsMenu(sf::RenderWindow& window, int screensizeX, int screenSizeY, int clockTime, int minClockTime);
	int getClockTime();
	int getMinClockTime();
private:
	int clockTime;
	int minClockTime;
};

