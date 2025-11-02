#include <SFML/Graphics.hpp>

int main()
{
	// -------------------------------------INITIALIZE-------------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	// creating a window
	//sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1336, 768)), "RPG Game");
	sf::RenderWindow window(sf::VideoMode({800,600}), "RPG Game");

	// Circle
	sf::CircleShape shape(50.0f);

	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(50.0f,50.0f);
	shape.setPosition(sf::Vector2f(400,300));
	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(8.0f);

	// Rectangle
	sf::RectangleShape box({ 100,50 });
	box.setOrigin(box.getSize() / 2.0f);
	box.setFillColor(sf::Color::Yellow);
	box.setPosition(sf::Vector2f(500, 100));
	box.setOutlineColor(sf::Color::Cyan);
	box.setOutlineThickness(8.0f);
	box.setRotation(45);

	// Trinagles?
	sf::CircleShape triangle(100.f, 3);
	triangle.setFillColor(sf::Color::Green);
	
	// -------------------------------------INITIALIZE-------------------------------------
	
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
		}
		// -------------------------------------UPDATE-------------------------------------

		// -------------------------------------DRAW-------------------------------------

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(box);
		window.draw(triangle);
		window.display();

		// -------------------------------------DRAW-------------------------------------
	}
	return 0;
}