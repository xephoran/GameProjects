#include "OptionsMenu.h"
#include <iostream>

OptionsMenu::OptionsMenu()
{
}

int OptionsMenu::runOptionsMenu(sf::RenderWindow& window, int screensizeX, int screenSizeY, int clockTime, int minClockTime)
{
	std::cout << "\nhas entered game menu class";
	//sets up rectangles for buttons
	// resume button has following Left:86, Top:58, Width:50, Height, 50
	sf::IntRect difficultyUp(766, 232, 50, 50);
	// options button has following Left:86, Top:231, Width:392, Height:110
	sf::IntRect difficultyDown(425, 232, 50, 50);
	// quit button has following Top:420m Left: 86, width 329, height 110
	sf::IntRect quitButton(18, 642, 273, 62);

	//creates the menu here
	sf::Texture menutexture;
	if (!menutexture.loadFromFile("images/options.png"))
	{
		std::cout << "\n\n\n\n\n\n-------ERROR COUDLNT LOAD MENU TEXTURE-----------\n\n\n\n\n\n\n\n";
		//error
	}
	//creates difficulty texture here
	sf::Texture difficultyTexture;
		if (clockTime == 6)
		{
			if (!menutexture.loadFromFile("images/easy.png"))
			{

			}
		}

		if (clockTime == 5)
		{
			if (!menutexture.loadFromFile("images/medium.png"))
			{

			}
		}

		if (clockTime == 4.5)
		{
			if (!menutexture.loadFromFile("images/hard.png"))
			{

			}
		}




	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (quitButton.contains(sf::Mouse::getPosition(window)) == true)
		{
			return 1;
		}
		if (difficultyDown.contains(sf::Mouse::getPosition(window)) == true)
		{
			if (clockTime == 5)
			{
				clockTime = 6;
				minClockTime = 2.9;
			}
			if (clockTime == 4.5)
			{
				clockTime = 5;
				minClockTime = 2.6;
			}
		}
		if (difficultyUp.contains(sf::Mouse::getPosition(window)) == true)
		{
			if (clockTime == 6)
			{
				clockTime = 5;
				minClockTime = 2.6;
			}
			if (clockTime == 5)
			{
				clockTime = 4.5;
				minClockTime = 2.2;
			}
		}
	}

	sf::Sprite menu;
	sf::Sprite difficulty;
	menu.setTexture(menutexture);
	difficulty.setTexture(difficultyTexture);
	window.draw(menu);
	window.draw(difficulty);
	window.display();
	std::cout << "should have drawn the menu";
	return 2;
}

int OptionsMenu::getClockTime()
{
	return clockTime;
}

int OptionsMenu::getMinClockTime()
{
	return minClockTime;
}
