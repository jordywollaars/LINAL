#pragma once

#include "RenderObject.hpp"
#include "Matrix.hpp"

class Projectile : public RenderObject
{
public:
	Projectile(Vector3<double> position, std::vector<Vector3<double>> localAxis);
	void update() override;
};