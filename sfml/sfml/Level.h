#pragma once
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level();
	int handleLevel(sf::RenderWindow& window, int levelFunction, int clockTime, int minClock);
	int drawLevel(sf::RenderWindow& window, int randomVar);
	int levelTimer(int clockFunction, int clockTime);
	int RNG(char coordType);
	void moveSprite(int x, int y);

private:
	sf::Sprite levelSprite;
};

