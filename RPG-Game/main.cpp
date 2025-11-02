#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// -------------------------------------INITIALIZE-------------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	// creating a window
	//sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1336, 768)), "RPG Game");
	sf::RenderWindow window(sf::VideoMode({800,600}), "RPG Game");

	//// Circle
	//sf::CircleShape shape(50.0f);

	//shape.setFillColor(sf::Color::Red);
	//shape.setOrigin(50.0f,50.0f);
	//shape.setPosition(sf::Vector2f(400,300));
	//shape.setOutlineColor(sf::Color::Blue);
	//shape.setOutlineThickness(8.0f);

	//// Rectangle
	//sf::RectangleShape box({ 100,50 });
	//box.setOrigin(box.getSize() / 2.0f);
	//box.setFillColor(sf::Color::Yellow);
	//box.setPosition(sf::Vector2f(500, 100));
	//box.setOutlineColor(sf::Color::Cyan);
	//box.setOutlineThickness(8.0f);
	//box.setRotation(45);

	//// Trinagles?
	//sf::CircleShape triangle(100.f, 3);
	//triangle.setFillColor(sf::Color::Green);
	
	// -------------------------------------INITIALIZE-------------------------------------

	// -------------------------------------LOAD-------------------------------------
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "player.png loaded successfully as a Texture." << std::endl;
		playerSprite.setTexture(playerTexture);

		int xIndex = 0, yIndex = 0;
		playerSprite.setTextureRect(sf::IntRect({ 64 * xIndex,64 * yIndex }, { 64,64 }));
		playerSprite.setScale({ 3,3 });
	}
	else
	{
		std::cout << "player.png failed to load as a Texture." << std::endl;
	}
	// -------------------------------------LOAD-------------------------------------
	
	//while the window is open, execute the code in body of loop
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

			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::D)
				{
					playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(10, 0));
					// polling rate is too slow for event
				}
			}*/
		}
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
		// -------------------------------------UPDATE-------------------------------------

		// -------------------------------------DRAW-------------------------------------

		window.clear(sf::Color::Black);
		/*window.draw(shape);
		window.draw(box);
		window.draw(triangle);*/
		window.draw(playerSprite);
		window.display();

		// -------------------------------------DRAW-------------------------------------
	}
	return 0;
}