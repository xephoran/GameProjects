//TODO set up way of passing sprites into the render engine, probably with a vector


#include <iostream>
#include "RenderEngine.h"
#include "MainMenu.h"
#include "GameLoop.h"

int main()
{
	//Declares needed classes and variables
	RenderEngine renderEngine;
	MainMenu mainMenu;
	GameLoop gameLoop;
	bool hasquit = false;
	int screenheight = 0;
	int screenwidth;

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
			std::cout << "Displaying Main Menu \n";
			gamestate = mainMenu.UseMenu();
		}

		while (gamestate == 2)
		{
			//needs to go to options menu eventually
		}

		while (gamestate == 3)
		{
			std::cout << "gamestate 3";
			gamestate = gameLoop.RunGame(screenheight);
			//main game function goes here
		}

		if (gamestate == 99)
		{
			hasquit = true;
		}
	}
	return 0;
}