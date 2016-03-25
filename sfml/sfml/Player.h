#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	int handlePlayer(sf::RenderWindow& window, int various);
	int Move(int direction);
	int CreatePlayer(sf::RenderWindow& window, int needed);
	int RenderPlayer(sf::RenderWindow& window, int various, int playerPositionX, int playerPositionY);
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};

