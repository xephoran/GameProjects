#pragma once
#include <SFML\Graphics.hpp>

class GameLoop
{
public:
	GameLoop();
	int RunGame(sf::RenderWindow& window, int screensizeX, int screenSizeY, int clockTime, int minClockTime);
private:
	sf::RenderWindow window;
};

