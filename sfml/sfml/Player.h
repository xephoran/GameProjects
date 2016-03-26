#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	int handlePlayer(sf::RenderWindow& window, int various);
	int movePlayer(sf::RenderWindow& window);
	int CreatePlayer(sf::RenderWindow& window, int needed);
	int RenderPlayer(sf::RenderWindow& window, int various);
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
};

