#pragma once
#include <SFML\Graphics.hpp>

class GameLoop
{
public:
	GameLoop();
	int RunGame(int screensize);
private:
	sf::RenderWindow window;
};

