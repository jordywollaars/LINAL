#pragma once

//#include "Matrix.hpp"
#include "Vector3.hpp"

#include <vector>
#include <math.h>

class RenderObject;

class Transform
{
public:
	Transform(RenderObject* renderObject = nullptr) : renderObject{ renderObject } {
		this->position = Vector3<double>((unsigned)3);
		this->scale = Vector3<double>((unsigned)3);
		this->rotation = Vector3<double>((unsigned)3);
	};

	void setScale(Vector3<double> scale);
	void setPosition(Vector3<double> position);
	void setRotation(Vector3<double> rotation);
private:
	Vector3<double> position;
	Vector3<double> scale;
	Vector3<double> rotation;

	RenderObject* renderObject;
};