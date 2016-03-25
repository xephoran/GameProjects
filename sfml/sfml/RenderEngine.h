#pragma once
#include <SFML\Graphics.hpp>

class RenderEngine
{
public:
	RenderEngine();
	~RenderEngine();
	int DisplayLogo();
	void WindowFunctions(sf::RenderWindow& window);
	void PutSpriteInStack(sf::Sprite sprite);
private:
	std::vector<sf::Sprite> stackOfSprites;
};

