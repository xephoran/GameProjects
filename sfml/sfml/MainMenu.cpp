#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

MainMenu::MainMenu()
{
}

int MainMenu::UseMenu()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game Name Place Holder", sf::Style::Fullscreen);

	//create main menu as texture
	sf::Texture texture;
	if (!texture.loadFromFile("images/mainmenu.png"))
	{
		std::cout << "couldnt load main menu";
	}

	//sets up rectangles for buttons
	//start game rect has following Left:86, Top:58, Width:329, Height, 110
	sf::IntRect startGameButton(86, 58, 329, 110);
	//options rect has following Left:86, Top:231, Width:392, Height:110
	sf::IntRect optionsButton(86, 231, 329, 110);
	//Quit rect has following Top:420m Left: 86, width 329, height 110
	sf::IntRect quitButton(86, 420, 329, 110);
	// run the program as long as the window is open

	//sets up music to play
	sf::Music music;
	if (!music.openFromFile("music/Overworld.ogg"))
	{
		std::cout << "couldnt load boot music\n"; // error
	}

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (quitButton.contains(sf::Mouse::getPosition(window)) == true)
				{
					window.close();
					return 99;
				}
				if (optionsButton.contains(sf::Mouse::getPosition(window)) == true)
				{
					window.close();
					return 2;
				}
				if (startGameButton.contains(sf::Mouse::getPosition(window)) == true)
				{
					window.close();
					return 3;
				}
			}
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);

		// end the current frame
		window.display();

		//plays music for the main menu on loop

		if (music.getStatus() != sf::Sound::Playing)
		{
			music.play();
		}

	}
	return 1;
}
