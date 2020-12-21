#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	const int windowWidth = 800;
	const int windowHeight = 600;

	std::cout << windowWidth << std::endl;
	std::cout << windowHeight << std::endl;
	
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Linal!");
	//window.setFramerateLimit(144);
	
	while (window.isOpen())
	{
		window.clear(sf::Color(255, 255, 255, 255));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	return 0;
}