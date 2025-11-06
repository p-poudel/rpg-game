#pragma once
#include <SFML/Graphics.hpp>
class FrameRate
{
	sf::Text frameRateText;
	sf::Font font;
	double timer = 0;
public:
	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();
	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

