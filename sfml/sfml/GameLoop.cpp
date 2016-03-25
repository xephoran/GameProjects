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
	RenderEngine renderEngine;
	Player player;
	
	std::string pressedkey = "0";
	
	window.create(sf::VideoMode(1280, 720), "My window", sf::Style::Fullscreen);

	int gamemenureturn = 0;

	while (hasquit == false)
	{
		std::cout << "has entered the while loop";
		//do whatever the game needs to do
		
		sf::Event event;
		window.clear();
		// while there are pending events...
		while (window.pollEvent(event))if (event.type == sf::Event::KeyPressed)
		{
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					pressedkey = "Escape";
				}
			}
		}

		//player class operations go here
		playerState = player.handlePlayer(window, 0);


		if (pressedkey == "Escape")
		{
			pressedkey = "0";
			bool inmenu = true;
			while (inmenu == true)
			{
				// escape key is pressed: open game menu
				std::cout << "\nentered game menu loop\n";

				while (window.pollEvent(event))if (event.type == sf::Event::KeyPressed)
				{
					{
						if (event.key.code == sf::Keyboard::Escape)
						{
							pressedkey = "Escape";
						}
					}
				}

				gamemenureturn = gameMenu.RunMenu(window);
				if (gamemenureturn == 1)
				{
					return 99;
				}
				if (gamemenureturn == 2)
				{
					return 2;
				}
				if (gamemenureturn == 3 || pressedkey == "Escape")
				{
					inmenu = false;
					pressedkey = "0";
				}
				std::cout << "\nentered last line of gamemenu loop\n";
			}
		}
		window.display();
	}
	return 99;
}
