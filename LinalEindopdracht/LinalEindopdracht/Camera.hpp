#pragma once

#include <SFML/Graphics.hpp>

#include "Vector3.hpp"
#include "Matrix.hpp"

#include "Scene.hpp"

class Camera {
public:
	Camera(Vector3<double> eyePosition, Vector3<double> lookAtPosition, Scene& scene);

	Matrix<double> getInverse();
	Matrix<double> originTranslate();

	void draw(sf::RenderWindow& window);

	void transform(Matrix<double> m);

	void setLookAtPosition(Vector3<double> lookAt);
private:
	Vector3<double> eyePosition;
	Vector3<double> lookAtPosition;

	Vector3<double> direction;
	Vector3<double> up = { 0, 1, 0, 1 };
	Vector3<double> right;

	Scene& scene;

	double near = 0.1;
	double far = 1000.0;
	double fovy = 60.0;
	double scale = near * std::tan(fovy * 0.5);
};