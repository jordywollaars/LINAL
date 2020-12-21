#pragma once

#include "Matrix.hpp"
#include "Vector2.hpp"

class Transform
{
public:
	Transform() {};
private:
	Vector2<double> position;
	Vector2<double> scale;
	double rotation;

	Matrix<double> transform;
};