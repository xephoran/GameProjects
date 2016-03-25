#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "RenderEngine.h"


Player::Player()
{
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
}

int Player::handlePlayer(sf::RenderWindow& window, int various)
{
	static int playerPositionX = 0;
	static int playerPositionY = 0;
	static int playerMade = 1;

	if (playerMade == 1)
	{
		CreatePlayer(window, 1);
		playerMade = 0;
	}
	
	RenderPlayer(window, 0, playerPositionX, playerPositionY);
	return 0;
}

int Player::CreatePlayer(sf::RenderWindow& window, int needed)
{
	if (!playerTexture.loadFromFile("images/player.png"))
	{
		std::cout << "couldnt load player";
	}
	playerSprite.setTexture(playerTexture);

	return 0;
}


int Player::Move(int direction)
{
	return 0;
}

int Player::RenderPlayer(sf::RenderWindow& window, int various, int playerPositionX, int playerPositionY)
{
	playerSprite.setPosition(playerPositionX, playerPositionY);
	window.draw(playerSprite);
	return 0;
}