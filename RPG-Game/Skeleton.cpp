#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton()
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1.0f);
}

void Skeleton::Load()
{
	if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "spritesheet.png loaded successfully as Enemy's Texture." << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition({ 1600,700 });

		int xIndex = 0, yIndex = 2;
		sprite.setTextureRect(sf::IntRect({ size.x * xIndex,size.y * yIndex }, size));
		sprite.setScale(scale);

		boundingRectangle.setSize(sf::Vector2f(size.x, size.y));
		boundingRectangle.setScale(scale);
	}
	else
	{
		std::cout << "spritesheet.png failed to load as Enemy's Texture." << std::endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}