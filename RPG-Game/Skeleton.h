#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;

	sf::RectangleShape boundingRectangle;

	sf::Vector2i size = { 64,64 };
	sf::Vector2f scale = sf::Vector2f(3.0f, 3.0f);

public:
	sf::Sprite sprite;
public:
	Skeleton();
	~Skeleton();
	void Initialize();
	void Load();

	void Shoot();
	void ReduceHp();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

