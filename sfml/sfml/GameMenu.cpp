#include "GameMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameMenu::GameMenu()
{
}

int GameMenu::enterMenu(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		bool inmenu = true;
		while (inmenu == true)
		{
			// escape key is pressed: open game menu
			int gamemenureturn = RunMenu(window);
			if (gamemenureturn == 1)
			{
				return 99;
			}
			if (gamemenureturn == 2)
			{
				return 2;
			}
			if (gamemenureturn == 3)
			{
				inmenu = false;
			}
		}
	}
	return 1;
}

int GameMenu::RunMenu(sf::RenderWindow& window)
{
	std::cout << "\nhas entered game menu class";
	//sets up rectangles for buttons
	// resume button has following Left:86, Top:58, Width:329, Height, 110
	sf::IntRect resumeButton(441, 275, 194, 56);
	// options button has following Left:86, Top:231, Width:392, Height:110
	sf::IntRect optionsButton(442, 352, 194, 56);
	// quit button has following Top:420m Left: 86, width 329, height 110
	sf::IntRect quitButton(442, 426, 194, 56);
	
	//creates the menu here
	sf::Texture menutexture;
	if (!menutexture.loadFromFile("images/gamemenu.png"))
	{
		std::cout << "\n\n\n\n\n\n-------ERROR COUDLNT LOAD MENU TEXTURE-----------\n\n\n\n\n\n\n\n";
		//error
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (quitButton.contains(sf::Mouse::getPosition(window)) == true)
		{
			return 1;
		}
		if (optionsButton.contains(sf::Mouse::getPosition(window)) == true)
		{
			return 2;
		}
		if (resumeButton.contains(sf::Mouse::getPosition(window)) == true)
		{
			return 3;
		}
	}

	sf::Sprite menu;
	menu.setTexture(menutexture);
	window.draw(menu);
	window.display();
	std::cout << "should have drawn the menu";
	return 0;
}