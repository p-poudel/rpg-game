#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
	if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "spritesheet.png loaded successfully as Enemy's Texture." << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition({ 400,100 });

		int xIndex = 0, yIndex = 2;
		sprite.setTextureRect(sf::IntRect({ 64 * xIndex,64 * yIndex }, { 64,64 }));
		sprite.setScale({ 3,3 });
	}
	else
	{
		std::cout << "spritesheet.png failed to load as Enemy's Texture." << std::endl;
	}
}

void Skeleton::Update()
{

}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}