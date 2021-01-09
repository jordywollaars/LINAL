#pragma once

#include "RenderObject.hpp"
#include "InputHandler.hpp"
#include "Scene.hpp"
#include "BoundingBox.hpp"
#include "Camera.hpp"

class Spaceship : public RenderObject, public BoundingBox
{
private:
	double moveSpeed = 10;
	double rotationSpeed = 50;

	InputHandler& inputHandler;
	Scene& scene;
	Camera& camera;

	bool lookAt = false;
public:
	Spaceship(InputHandler& inputHandler, Scene& scene, Camera& camera);
	void shoot(double relativeSpeed);

	void update(double deltaTime);

	void onCollision(BoundingBox* other) override;
};