//TODO set up way of passing sprites into the render engine, probably with a vector


#include <iostream>
#include "RenderEngine.h"
#include "MainMenu.h"
#include "GameLoop.h"
#include "OptionsMenu.h"
#include <SFML/Graphics.hpp>

int main()
{
	//Declares needed classes and variables
	RenderEngine renderEngine;
	MainMenu mainMenu;
	GameLoop gameLoop;
	bool hasquit = false;
	int screenheight = 0;
	int screenwidth = 0;
	int clockTime = 6;
	int minClockTime = 2.9;
	OptionsMenu optionsMenu;
	sf::RenderWindow window;
	bool firsttime = true;

	while (!hasquit)
	{
		int gamestate = 0;

		while (gamestate == 0)
		{
			std::cout << "Displaying Logo\n";
			gamestate = renderEngine.DisplayLogo();
		}

		while (gamestate == 1)
		{
			if (firsttime)
			{
				firsttime = false;
				window.create(sf::VideoMode(1280, 720), "My window", sf::Style::Fullscreen);
			}
			std::cout << "Displaying Main Menu \n";
			gamestate = mainMenu.UseMenu();
		}

		while (gamestate == 2)
		{
			//needs to go to options menu eventually
			gamestate = optionsMenu.runOptionsMenu(window, screenwidth, screenheight, clockTime, minClockTime);
			clockTime = optionsMenu.getClockTime();
			minClockTime = optionsMenu.getMinClockTime();
		}

		while (gamestate == 3)
		{
			std::cout << "gamestate 3";
			gamestate = gameLoop.RunGame(window, 0, 0, clockTime, minClockTime);
			//main game function goes here
		}

		if (gamestate == 99)
		{
			hasquit = true;
		}
	}
	return 0;
}