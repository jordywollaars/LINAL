#pragma once

#include "RenderObject.hpp"
#include "Matrix.hpp"
#include "BoundingBox.hpp"
#include "Scene.hpp"

class Projectile : public RenderObject, public BoundingBox
{
public:
	Projectile(Vector3<double> position, std::vector<Vector3<double>> localAxis, Scene& scene);
	void update(double deltaTime) override;

	void onCollision(BoundingBox* other) override;
private:
	Scene& scene;

	const double speed = 15;
	double lifeTimeInSeconds = 5;
};