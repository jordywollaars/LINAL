#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Scene.hpp"

int main() {
	const int windowWidth = 800;
	const int windowHeight = 600;

	std::cout << windowWidth << std::endl;
	std::cout << windowHeight << std::endl;
	
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Linal!");
	//window.setFramerateLimit(144);

	Scene* scene = new Scene();
	RenderObject* renderObject = new RenderObject();
	//renderObject->setStarRenderObject();
	renderObject->setShipRenderObject();
	scene->add(renderObject);
		
	while (window.isOpen())
	{
		window.clear(sf::Color(0, 0, 0, 255));

		/*sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}*/

		scene->update();
		scene->render(window);

		window.display();
	}

	delete scene;
	delete renderObject;

	return 0;
}