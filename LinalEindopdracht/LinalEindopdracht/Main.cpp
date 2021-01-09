#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Scene.hpp"
#include "Camera.hpp"
#include "Matrix.hpp"

#include "Target.hpp"
#include <random>

#include "InputHandler.hpp"
#include "Planet.hpp"
#include "Spaceship.hpp"

int main() {
	const int windowWidth = 800;
	const int windowHeight = 600;

	std::cout << windowWidth << std::endl;
	std::cout << windowHeight << std::endl;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Linal!");
	//window.setFramerateLimit(144);

	InputHandler* inputHandler = new InputHandler();

	Scene* scene = new Scene();
	Camera* camera = new Camera(Vector3<double>(0, 10, 50), Vector3<double>(0, 0, 0), *scene, *inputHandler);
	scene->add(camera);

	RenderObject* spaceShip = new Spaceship(*inputHandler, *scene, *camera);
	//spaceShip->transformObject(Matrix<double>::getTranslationMatrix(20, 20, 20));
	scene->add(spaceShip);
	//renderObject->setStarRenderObject();
	//spaceShip->setShipRenderObject();

	std::vector<BoundingBox*> boundingBoxes = std::vector<BoundingBox*>();

	Target* target = new Target();
	target->setSphereRenderObject(4);
	target->transformObject(Matrix<double>::getScalingMatrix(4, 4, 4));
	target->transformObject(Matrix<double>::getTranslationMatrix(6.4, 22.4, -41.6));
	scene->add(target);

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<double> uni(0, 100);

	/*for (int i = 0; i < 10; i++)
	{
		RenderObject* sphere = new Planet();
		sphere->setSphereRenderObject(0);
		scene->add(sphere);

		sphere->transformObject(Matrix<double>::getScalingMatrix(4, 4, 4));
		double x = uni(rng) - 50;
		double y = uni(rng) - 50;
		double z = uni(rng) - 50;
		sphere->transformObject(Matrix<double>::getTranslationMatrix(x, y, z));
	}*/

	sf::Clock deltaClock;
	while (window.isOpen())
	{
		window.clear(sf::Color(0, 0, 0, 255));
		inputHandler->clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
			{
				inputHandler->input(event);
			}
		}

		sf::Time dt = deltaClock.restart();
		
		scene->update(dt.asSeconds());
		scene->updateCollisions();
		camera->draw(window);

		window.display();
	}

	delete scene;
	delete spaceShip;

	return 0;
}