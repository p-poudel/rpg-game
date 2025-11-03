#include "Player.h"
#include "Math.h"

void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1.0f);

}

void Player::Load()
{
	if (texture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		std::cout << "spritesheet.png loaded successfully as Player's Texture." << std::endl;
		sprite.setTexture(texture);

		int xIndex = 0, yIndex = 0;
		sprite.setTextureRect(sf::IntRect({ size.x * xIndex,size.y * yIndex }, size));
		sprite.setScale(scale);

		boundingRectangle.setSize(sf::Vector2f(size.x,size.y));
		boundingRectangle.setScale(scale);
		sprite.setPosition(0, 0);
	}
	else
	{
		std::cout << "spritesheet.png failed to load as Player's Texture." << std::endl;
	}
}

void Player::Shoot()
{
	//
}
void Player::ReduceHp()
{
	//
}
void Player::Update(Skeleton& skeleton)
{
	sf::Vector2f currentPosition = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(currentPosition + sf::Vector2f(0, -1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(currentPosition + sf::Vector2f(-1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(currentPosition + sf::Vector2f(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(currentPosition + sf::Vector2f(1, 0));
	}

	boundingRectangle.setPosition(sprite.getPosition());

	// Bullets
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());


	}

	for (int i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}

	if (Math::CheckBoolCollision(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
	{
		std::cout << "COLLISION" << std::endl;
	}
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}