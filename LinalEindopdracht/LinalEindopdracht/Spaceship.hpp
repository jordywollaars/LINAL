#pragma once

#include "RenderObject.hpp"
#include "InputHandler.hpp"
#include "Scene.hpp"
#include "BoundingBox.hpp"

class Spaceship : public RenderObject, public BoundingBox
{
private:
	double moveSpeed = 10;
	double rotationSpeed = 50;

	InputHandler& inputHandler;
	Scene& scene;
public:
	Spaceship(InputHandler& inputHandler, Scene& scene);
	void shoot();

	void update(double deltaTime);

	void onCollision(BoundingBox* other) override;

	Matrix<double> rotationMatrix(Vector3<double> rotationAxis, Vector3<double> centre, double degrees);
};