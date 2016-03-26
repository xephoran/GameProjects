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
	int playerMoveX = NULL;
	int playerMoveY = NULL;

	if (playerMade == 1)
	{
		CreatePlayer(window, 1);
		playerMade = 0;
	}

	movePlayer(window);

	RenderPlayer(window, 0);
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

int Player::RenderPlayer(sf::RenderWindow& window, int various)
{
	window.draw(playerSprite);
	return 0;
}

int Player::movePlayer(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.move(1, 0);
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.move(-1, 0);
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerSprite.move(0, -1);
	}
		return 0;

}