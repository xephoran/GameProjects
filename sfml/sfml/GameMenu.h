#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class GameMenu
{
public:
	GameMenu();
	int RunMenu(sf::RenderWindow& window);
	int enterMenu(sf::RenderWindow& window);
};

