#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrtf(vector.x * vector.x + vector.y * vector. y);
	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{
	// -------------------------------------INITIALIZE-------------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	// creating a window
	sf::RenderWindow window(sf::VideoMode({1920,1080}), "RPG Game", sf::Style::Default, settings);
	
	// -------------------------------------INITIALIZE-------------------------------------
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	
	// -------------------------------------LOAD-------------------------------------
	sf::Texture playerTexture, skeletonTexture;
	sf::Sprite playerSprite, skeletonSprite;

	// -------------------------------------PLAYER-------------------------------------
	if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "spritesheet.png loaded successfully as Player's Texture." << std::endl;
		playerSprite.setTexture(playerTexture);

		int xIndex = 0, yIndex = 0;
		playerSprite.setTextureRect(sf::IntRect({ 64 * xIndex,64 * yIndex }, { 64,64 }));
		playerSprite.setScale({ 3,3 });
		playerSprite.setPosition(1650,800);
	}
	else
	{
		std::cout << "spritesheet.png failed to load as Player's Texture." << std::endl;
	}
	// -------------------------------------PLAYER-------------------------------------

	// -------------------------------------SKELETON-------------------------------------
	if (skeletonTexture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "spritesheet.png loaded successfully as Enemy's Texture." << std::endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setPosition({400,100});

		int xIndex = 0, yIndex = 2;
		skeletonSprite.setTextureRect(sf::IntRect({ 64 * xIndex,64 * yIndex }, { 64,64 }));
		skeletonSprite.setScale({ 3,3 });
	}
	else
	{
		std::cout << "spritesheet.png failed to load as Enemy's Texture." << std::endl;
	}
	// -------------------------------------SKELETON-------------------------------------
	// -------------------------------------LOAD-------------------------------------
	
	//while the window is open, execute the code in body of loop
	// main game loop
	while (window.isOpen())
	{
		// -------------------------------------UPDATE-------------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
					window.close();
			}
		}

		//bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

		sf::Vector2f currentPosition = playerSprite.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			playerSprite.setPosition( currentPosition + sf::Vector2f(0, -1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.setPosition(currentPosition + sf::Vector2f(-1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerSprite.setPosition(currentPosition + sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.setPosition(currentPosition + sf::Vector2f(1, 0));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());


		}

		for (int i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizeVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
		// -------------------------------------UPDATE-------------------------------------

		// -------------------------------------DRAW-------------------------------------

		window.clear(sf::Color::Black);
		window.draw(skeletonSprite);
		window.draw(playerSprite);
		
		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		window.display();

		// -------------------------------------DRAW-------------------------------------
	}
	return 0;
}