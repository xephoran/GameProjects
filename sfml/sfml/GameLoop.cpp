#include "GameLoop.h"
#include "GameMenu.h"
#include "RenderEngine.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "Player.h"

GameLoop::GameLoop()
{
}

int GameLoop::RunGame(int screensize)
{
	//Defines variables and classes that will be needed/passed around and initialize the first level/only level
	bool hasquit = false;
	bool inmenu = false;
	int playerState;
	GameMenu gameMenu;
	Player player;
	int menuReturn = NULL;

	//sets up the window (needs to happen ONCE)
	window.create(sf::VideoMode(1280, 720), "My window", sf::Style::Fullscreen);

	while (hasquit == false)
	{
		std::cout << "has entered the while loop";
		//do whatever the game needs to do

		window.clear();

		//player class operations go here
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
