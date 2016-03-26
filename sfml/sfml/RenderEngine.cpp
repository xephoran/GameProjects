#include "RenderEngine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Timer.h"
#include <iostream>

RenderEngine::RenderEngine()
{
}


RenderEngine::~RenderEngine()
{
}

int RenderEngine::DisplayLogo()
{
	
	//creates timer for displaying logo 4(s)
	Timer timer;

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "images/Logo", sf::Style::None);

	//sets up music to play
	sf::Music music;
	if (!music.openFromFile("music/bootmusic.ogg"))
	{
		std::cout << "couldnt load boot music\n"; // error
	}

	//loads up the logo as a texture
	sf::Texture texture;
	if (!texture.loadFromFile("images/logo.png"))
	{
		std::cout << "couldnt load logo";
	}

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{	
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//timer to display window right amount of time
		//uses timer to close window if not requested earlier

		if (timer.isRunning()) {
			timer.stop();
		}
		else {
			timer.start();
		}

		if (timer.getTime() > 1600)
		{
			std::cout << "Timer tripped loop";
			window.close();
			return 1;
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);

		// end the current frame
		window.display();

		//plays music for the logo splash

		if (music.getStatus() != sf::Sound::Playing)
		{
			music.play();
		}
	}

	return 0;
}
