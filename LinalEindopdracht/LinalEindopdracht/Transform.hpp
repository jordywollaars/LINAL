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
		this->position = Vector<double>((unsigned)2);
		this->scale = Vector<double>((unsigned)2);
	};


	void setScale(Vector2<double> scale);
	void setPosition(Vector2<double> position);
	void setRotation(double rotation);
private:
	Vector<double> position;
	Vector<double> scale;
	double rotation;

	RenderObject* renderObject;

	Matrix<double> scaleMatrix;
	Matrix<double> positionMatrix;
	Matrix<double> rotationMatrix;
	void scaleTranslate(std::vector<Vector<double>>& vertices);
	void positionTranslate(std::vector<Vector<double>>& vertices);
	void rotationTranslate(std::vector<Vector<double>>& vertices);
};