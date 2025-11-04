#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"


int main()
{
	// -------------------------------------INITIALIZE-------------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	// creating a window
	sf::RenderWindow window(sf::VideoMode({1920,1080}), "RPG Game", sf::Style::Default, settings);
	//window.setVerticalSyncEnabled(true); //enable v-sync
	window.setFramerateLimit(240);
	// -------------------------------------INITIALIZE-------------------------------------
	
	
	Player player;
	Skeleton skeleton;

	player.Initialize();
	skeleton.Initialize();

	// -------------------------------------LOAD-------------------------------------
	player.Load();
	skeleton.Load();
	// -------------------------------------LOAD-------------------------------------
	
	sf::Clock clock;
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

		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();
		skeleton.Update(deltaTime);
		player.Update(skeleton, deltaTime);

		
		// -------------------------------------UPDATE-------------------------------------

		// -------------------------------------DRAW-------------------------------------

		window.clear(sf::Color::Black);

		skeleton.Draw(window);
		player.Draw(window);
		
		
		window.display();

		// -------------------------------------DRAW-------------------------------------
	}
	return 0;
}