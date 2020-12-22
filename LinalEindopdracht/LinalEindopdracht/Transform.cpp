#include "Transform.hpp"
#include "RenderObject.hpp"

void Transform::setScale(Vector2<double> scale)
{
	this->scale = Vector<double>(scale.x, scale.y);
	//Vector<double> CalculationVector(scale.x, scale.y);

	scaleTranslate(renderObject->getVertices());
}

void Transform::setPosition(Vector2<double> position)
{
	this->position = Vector<double>(position.x, position.y);
	//Vector<double> CalculationVector(position.x, position.y);

	positionTranslate(renderObject->getVertices());
}

void Transform::scaleTranslate(std::vector<Vector<double>>& vertices)
{
	Matrix<double> toOriginMatrix = Matrix<double>(3, 3);
	toOriginMatrix(0, 0) = 1;
	toOriginMatrix(1, 1) = 1;
	toOriginMatrix(2, 2) = 1;
	toOriginMatrix(0, 2) = this->renderObject->getPivot()[0];
	toOriginMatrix(1, 2) = this->renderObject->getPivot()[1];

	Matrix<double> scalingMatrix = Matrix<double>(3, 3);
	scalingMatrix(0, 0) = this->scale[0];
	scalingMatrix(1, 1) = this->scale[1];
	scalingMatrix(2, 2) = 1;

	Matrix<double> backToLocalMatrix = Matrix<double>(3, 3);
	backToLocalMatrix(0, 0) = 1;
	backToLocalMatrix(1, 1) = 1;
	backToLocalMatrix(2, 2) = 1;
	backToLocalMatrix(0, 2) = -this->renderObject->getPivot()[0];
	backToLocalMatrix(1, 2) = -this->renderObject->getPivot()[1];
	toOriginMatrix.print();
	scalingMatrix.print();
	backToLocalMatrix.print();

	scaleMatrix = toOriginMatrix * scalingMatrix * backToLocalMatrix;

	std::cout << "----------------------------" << std::endl;
	scaleMatrix.print();

	for (Vector<double>& vertex : vertices)
	{
		vertex.push(1);
		Vector<double> temp = scaleMatrix * vertex;
		vertex[0] = temp[0];
		vertex[1] = temp[1];
		vertex.popBack();
	}
}

void Transform::positionTranslate(std::vector<Vector<double>>& vertices)
{
	positionMatrix = Matrix<double>(3, 3);
	positionMatrix(0, 0) = 1;
	positionMatrix(1, 1) = 1;
	positionMatrix(2, 2) = 1;
	positionMatrix(0, 2) = this->position[0];
	positionMatrix(1, 2) = this->position[1];

	for (Vector<double>& vertex : vertices)
	{
		vertex.push(1);
		Vector<double> temp = positionMatrix * vertex;
		vertex[0] = temp[0];
		vertex[1] = temp[1];
		vertex.popBack();
	}

	Vector<double>& pivot = this->renderObject->getPivot();
	pivot.push(1);
	Vector<double> temp = positionMatrix * pivot;
	pivot[0] = temp[0];
	pivot[1] = temp[1];
	pivot.popBack();
}
