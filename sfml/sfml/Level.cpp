#include "Level.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Level::Level()
{
	sf::Sprite levelSprite;
}

int Level::handleLevel(sf::RenderWindow& window, int levelFunction, int clockTime, int minClock)
{
	static int levelTimerReturn = 0;
	static int levelPositionX = 0;
	static int levelPositionY = 0;
	
	if (levelTimerReturn == 0)
	{
		levelPositionX = RNG('x');
		levelPositionY = RNG('y');
		moveSprite(levelPositionX, levelPositionY);
		levelTimerReturn = levelTimer(1, clockTime);
	}
	else if (levelTimerReturn == 1)
	{
		levelTimerReturn = levelTimer(1, clockTime);
	}
	else if (levelTimerReturn == 2)
	{
		levelTimerReturn = levelTimer(2, clockTime);
		if (clockTime >= minClock)
		{
			clockTime = clockTime - (0.1);
		}
	}

	drawLevel(window, 0);
	return 0;
}

int Level::drawLevel(sf::RenderWindow& window, int randomVar)
{
	sf::Texture levelTexture;
	if (!levelTexture.loadFromFile("images/level.png"))
	{
	
	}
	levelSprite.setTexture(levelTexture);

	window.draw(levelSprite);
	return 0;
}

int Level::levelTimer(int clockFunction, int clockTime)
{
	static sf::Clock clock;
	if (clockFunction == 1)
	{
		sf::Time elapsed = clock.getElapsedTime();
		sf::Time t1 = sf::seconds(clockTime);
		if (elapsed >= t1)
		{
			return 2;
		}
	}

	if (clockFunction == 2)
	{
		clock.restart();
		return 0;
	}
	return 1;
}

int Level::RNG(char coordType)
{
	static int hasBeenInitialized = 0;
	
	if (hasBeenInitialized == 0)
	{
		srand(time(NULL));
		hasBeenInitialized = 1;
	}

	static int randomNumber = NULL;

	if (coordType == 'x')
	{
		randomNumber =1 + rand() %1190;
		std::cout << "\n\n\n" << randomNumber << "\n\n\n";
		return randomNumber;
	}
	if (coordType == 'y')
	{
		randomNumber = 1 + rand() % 630;
		std::cout << "\n\n\n" << randomNumber << "\n\n\n";
		return randomNumber;
	}
}

void Level::moveSprite(int x, int y)
{
	levelSprite.setPosition(x, y);
	return;
}

/*
things that need to be done:
Create the level sprite which is an area that the player needs to get into
create a random number for the location of the level sprite
set a texture somewhere for the sprite
get the player sprites position

dimensions of the level sprite: (90x90)
*/