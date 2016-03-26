#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	int handlePlayer(sf::RenderWindow& window, int various);
	int movePlayerRight(sf::RenderWindow& window);
	int movePlayerUp(sf::RenderWindow& window);
	int CreatePlayer(sf::RenderWindow& window, int needed);
	int RenderPlayer(sf::RenderWindow& window, int various, int playerPositionX, int playerPositionY);
	int Player::playerPositionCheckX(int positionX);
	int Player::playerPositionCheckY(int positionY);
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};

