#include  <iostream>
#include <SFML\Graphics.hpp>
#include "json.hpp"

//I tried to create json objects, but i didn't find how to use it, i will try to implement json during the week 16-23 October
using json = nlohmann::json;

int main()
{
	const float circle_radius = 50.;
	const int window_height = 500;
	const int window_width = 500;
	const float framerate = 60.;
	const int square_length = 100;


	json circle_object = {"radius", 50};
	
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Collider game");
	window.setFramerateLimit(framerate);

	sf::CircleShape circle;
	circle.setRadius(circle_radius);
	circle.setFillColor(sf::Color::Green);

	sf::RectangleShape square;
	square.setSize(sf::Vector2f(square_length, square_length));
	square.setFillColor(sf::Color::Blue);
	square.setPosition(window_width/2 - square_length/2, window_height/2 - square_length/2);
	
	float speed = 5.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f delta_move;

		//Manage inputs
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (circle.getPosition().x <= 0)
			{
				delta_move.x -= 0.0f;
			}
			else
			{
				delta_move.x -= 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (circle.getPosition().x + circle.getRadius() * 2 >= window.getSize().x)
			{
				delta_move.x += 0.0f;
			}
			else
			{
				delta_move.x += 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (circle.getPosition().y <= 0)
			{
				delta_move.y -= 0.0f;
			}
			else
			{
				delta_move.y -= 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (circle.getPosition().y + circle.getRadius() *2 >= window.getSize().y)
			{
				delta_move.y += 0.0f;
			}
			else
			{
				delta_move.y += 1.0f;
			}
		}
		if(circle.getGlobalBounds().intersects(square.getGlobalBounds()))
		{
			circle.setFillColor(sf::Color::Red);
			square.setFillColor(sf::Color::Red);
		}
		else
		{
			circle.setFillColor(sf::Color::Green);
			square.setFillColor(sf::Color::Blue);
		}

		circle.setPosition(circle.getPosition() + delta_move*speed);
		
		window.clear();
		window.draw(circle);
		window.draw(square);
		window.display();
	}

	return 0;
}
// done with Strub Tanguy