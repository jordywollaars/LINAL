#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Vector2.hpp"

#include <vector>

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
private:
	Vector<double> position;
	Vector<double> scale;
	double rotation;

	RenderObject* renderObject;

	Matrix<double> scaleMatrix;
	Matrix<double> positionMatrix;
	void scaleTranslate(std::vector<Vector<double>>& vertices);
	void positionTranslate(std::vector<Vector<double>>& vertices);
};