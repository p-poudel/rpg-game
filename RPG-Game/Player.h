#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include <iostream>

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	float speed = 1.0f;

	sf::RectangleShape boundingRectangle;

	sf::Vector2i size = { 64,64 };
	sf::Vector2f scale = sf::Vector2f(3.0f, 3.0f);

public:
	sf::Sprite sprite;
public:
	void Initialize();
	void Load();

	void Shoot();
	void ReduceHp();
	void Update(Skeleton& skeleton, float deltaTime);
	void Draw(sf::RenderWindow& window);
};