#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Vector2.hpp"

#include <vector>
#include <math.h>

class RenderObject;

class Transform
{
public:
	Transform(RenderObject* renderObject = nullptr) : renderObject{ renderObject } {
		this->position = Vector<double>((unsigned)3);
		this->scale = Vector<double>((unsigned)3);
		this->rotation = Vector<double>((unsigned)3);
	};


	void setScale(Vector3<double> scale);
	void setPosition(Vector3<double> position);
	void setRotation(Vector3<double> rotation);
private:
	Vector<double> position;
	Vector<double> scale;
	Vector<double> rotation;

	RenderObject* renderObject;

	Matrix<double> scaleMatrix;
	Matrix<double> positionMatrix;
	Matrix<double> rotationMatrix;
	void scaleTranslate(std::vector<Vector<double>>& vertices);
	void positionTranslate(std::vector<Vector<double>>& vertices);
	void rotationTranslate(std::vector<Vector<double>>& vertices);
};