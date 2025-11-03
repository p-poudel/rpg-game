#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;
public:
	void Initialize();
	void Load();

	void Shoot();
	void ReduceHp();
	void Update();
	void Draw(sf::RenderWindow& window);
};

