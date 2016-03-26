#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "GameLoop.h"
#include "GameMenu.h"
#include "RenderEngine.h"
#include "Player.h"
#include "Level.h"

GameLoop::GameLoop()
{
}

int GameLoop::RunGame(sf::RenderWindow& window, int screensizeX, int screenSizeY, int difficulty, int difficulty2)
{
	//Defines variables and classes that will be needed/passed around and initialize the first level/only level
	bool hasquit = false;
	bool inmenu = false;
	int playerState;
	int levelState;
	GameMenu gameMenu;
	Player player;
	Level level;
	int menuReturn = NULL;

	while (hasquit == false)
	{
		//do whatever the game needs to do iteratively
		
		//starts new iterations by clearing the window
		window.clear();

		//starts with level class first
		levelState = level.handleLevel(window, 0, difficulty, difficulty2);

		//starts by handling the player class
		playerState = player.handlePlayer(window, 0);


		//this opens the game menu if the button is pressed
			menuReturn = gameMenu.enterMenu(window);
			if (menuReturn == 99 || menuReturn == 2)
			{
				return menuReturn;
			}

		window.display();
	}
	return 99;
}
