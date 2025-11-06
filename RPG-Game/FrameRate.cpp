#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : timer(0)
{
	
}
FrameRate::~FrameRate()
{
}
void FrameRate::Initialize()
{
}
void FrameRate::Load()
{
	if (font.loadFromFile("assets/fonts/arial.ttf"))
	{
		std::cout << "Arial.ttf loaded as font!" << std::endl;
		frameRateText.setFont(font);
	}
	else
	{
		std::cout << "Failed to load a font" << std::endl;
	}
}
void FrameRate::Update(double deltaTime)
{
	timer += deltaTime;
	if (timer >= 125.0)
	{
		std::string text = "FPS: " + std::to_string((int)(1000 / deltaTime)) + "\nframeTime : " + std::to_string((int)deltaTime);
		frameRateText.setString(text);
		timer = 0;
	}
}
void FrameRate::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}