#pragma once

#include <SFML/Graphics.hpp>

#include "Vector3.hpp"
#include "Matrix.hpp"

#include "Scene.hpp"
#include "InputHandler.hpp"

class Camera : public GameObject {
public:
	Camera(Vector3<double> eyePosition, Vector3<double> lookAtPosition, Scene& scene, InputHandler& inputHandler);

	Matrix<double> getInverse();
	Matrix<double> originTranslate();

	void drawLine(Vector3<double> begin, Vector3<double> end, Matrix<double> pm, Matrix<double> m, sf::Color color, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	void transformPosition(Matrix<double> m);

	void setLookAtPosition(Vector3<double> lookAt);

	void update(double deltaTime);
private:
	Vector3<double> eyePosition;
	Vector3<double> lookAtPosition;

	Vector3<double> direction;
	Vector3<double> up = { 0, 1, 0, 1 };
	Vector3<double> right;

	Scene& scene;
	InputHandler& inputHandler;

	double moveSpeed = 5;
	double rotationSpeed = 15;

	double near;
	double far;
	double fovy;
	double scale;
};