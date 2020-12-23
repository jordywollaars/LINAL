#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Scene.hpp"
#include "Matrix.hpp"

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

	for (int i = 0; i < 35; i++)
	{

		Matrix<double> translationMatrixNegZ = Matrix<double>::getTranslationMatrix(.0, .0, -1.0 * 10);
		renderObject->transform(translationMatrixNegZ);
	}

	while (window.isOpen())
	{
		window.clear(sf::Color(0, 0, 0, 255));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				//Movement
				if (event.key.code == sf::Keyboard::Key::D)
				{
					Matrix<double> translationMatrixPosX = Matrix<double>::getTranslationMatrix(1.0*10, .0, .0);
					renderObject->transform(translationMatrixPosX);
				}

				if (event.key.code == sf::Keyboard::Key::A)
				{
					Matrix<double> translationMatrixNegX = Matrix<double>::getTranslationMatrix(-1.0 * 10, .0, .0);
					renderObject->transform(translationMatrixNegX);
				}

				if (event.key.code == sf::Keyboard::Key::W)
				{
					Matrix<double> translationMatrixPosY = Matrix<double>::getTranslationMatrix(.0, -1.0 * 10, .0);
					renderObject->transform(translationMatrixPosY);
				}

				if (event.key.code == sf::Keyboard::Key::S)
				{
					Matrix<double> translationMatrixNegY = Matrix<double>::getTranslationMatrix(.0, 1.0 * 10, .0);
					renderObject->transform(translationMatrixNegY);
				}

				if (event.key.code == sf::Keyboard::Key::E)
				{
					Matrix<double> translationMatrixPosZ = Matrix<double>::getTranslationMatrix(.0, .0, 1.0 * 10);
					renderObject->transform(translationMatrixPosZ);
				}

				if (event.key.code == sf::Keyboard::Key::Q)
				{
					Matrix<double> translationMatrixNegZ = Matrix<double>::getTranslationMatrix(.0, .0, -1.0 * 10);
					renderObject->transform(translationMatrixNegZ);
				}

				//Scaling
				if (event.key.code == sf::Keyboard::Key::Up)
				{
					Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(renderObject->getPivot().x, renderObject->getPivot().y, renderObject->getPivot().z);
					Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(1.1, 1.1, 1.1);
					Matrix<double> back = Matrix<double>::getTranslationMatrix(-renderObject->getPivot().x, -renderObject->getPivot().y, -renderObject->getPivot().z);
					renderObject->transform(toOrigin * upscaleMatrix * back);
				}

				if (event.key.code == sf::Keyboard::Key::Down)
				{
					Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(renderObject->getPivot().x, renderObject->getPivot().y, renderObject->getPivot().z);
					Matrix<double> downscaleMatrix = Matrix<double>::getScalingMatrix(0.9, 0.9, 0.9);
					Matrix<double> back = Matrix<double>::getTranslationMatrix(-renderObject->getPivot().x, -renderObject->getPivot().y, -renderObject->getPivot().z);
					renderObject->transform(toOrigin * downscaleMatrix * back);
				}

				//Rotating
				/*if (event.key.code == sf::Keyboard::Key::R)
				{
					Matrix<double> toOrigin = Matrix<double>::getTranslationMatrix(renderObject->getPivot().x, renderObject->getPivot().y, renderObject->getPivot().z);
					Matrix<double> upscaleMatrix = Matrix<double>::getScalingMatrix(1.1, 1.1, 1.1);
					Matrix<double> back = Matrix<double>::getTranslationMatrix(-renderObject->getPivot().x, -renderObject->getPivot().y, -renderObject->getPivot().z);
					renderObject->transform(toOrigin * upscaleMatrix * back);
				}*/
			}
		}

		scene->update();
		scene->render(window);

		window.display();
	}

	delete scene;
	delete renderObject;

	return 0;
}