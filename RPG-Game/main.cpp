#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"


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
	FrameRate frameRate;
	Player player;
	Skeleton skeleton;

	frameRate.Initialize();
	player.Initialize();
	skeleton.Initialize();

	// -------------------------------------LOAD-------------------------------------
	frameRate.Load();
	player.Load();
	skeleton.Load();
	// -------------------------------------LOAD-------------------------------------
	
	sf::Clock clock;
	sf::Time deltaTimeTimer;
	//while the window is open, execute the code in body of loop
	// main game loop
	while (window.isOpen())
	{
		clock.restart();
		// -------------------------------------UPDATE-------------------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
					window.close();
			}
		}

		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000;
		
		//std::cout << std::endl;

		frameRate.Update(deltaTime);
		skeleton.Update(deltaTime);
		player.Update(skeleton, deltaTime);

		
		// -------------------------------------UPDATE-------------------------------------

		// -------------------------------------DRAW-------------------------------------

		window.clear(sf::Color::Black);

		skeleton.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);
		window.display();
		deltaTimeTimer = clock.getElapsedTime();
		// -------------------------------------DRAW-------------------------------------
	}
	return 0;
}