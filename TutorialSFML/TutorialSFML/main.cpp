#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::Sprite background;

	sf::Texture texture;

	if (!texture.loadFromFile("Vertex Example.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	background.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			case sf::Event::Resized:
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));

				break;

			}
		}

		window.clear();

		window.draw(background);

		window.display();
	}
}