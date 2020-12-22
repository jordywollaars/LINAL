#include "Transform.hpp"
#include "RenderObject.hpp"

void Transform::setScale(Vector3<double> scale)
{
	this->scale = Vector<double>(scale.x, scale.y, scale.z);
	//Vector<double> CalculationVector(scale.x, scale.y);

	scaleTranslate(renderObject->getVertices());
}

void Transform::setPosition(Vector3<double> position)
{
	this->position = Vector<double>(position.x, position.y, position.z);
	//Vector<double> CalculationVector(position.x, position.y);

	positionTranslate(renderObject->getVertices());
}

void Transform::setRotation(Vector3<double> rotation)
{
	this->rotation = Vector<double>(rotation.x, rotation.y, rotation.z);

	rotationTranslate(renderObject->getVertices());
}

void Transform::scaleTranslate(std::vector<Vector<double>>& vertices)
{
	/*Matrix<double> toOriginMatrix = Matrix<double>(3, 3);
	toOriginMatrix(0, 0) = 1;
	toOriginMatrix(1, 1) = 1;
	toOriginMatrix(2, 2) = 1;
	toOriginMatrix(0, 2) = this->renderObject->getPivot()[0];
	toOriginMatrix(1, 2) = this->renderObject->getPivot()[1];*/

	this->scaleMatrix = Matrix<double>(4, 4);
	this->scaleMatrix(0, 0) = this->scale[0];
	this->scaleMatrix(1, 1) = this->scale[1];
	this->scaleMatrix(2, 2) = this->scale[2];
	this->scaleMatrix(3, 3) = 1;

	/*Matrix<double> backToLocalMatrix = Matrix<double>(3, 3);
	backToLocalMatrix(0, 0) = 1;
	backToLocalMatrix(1, 1) = 1;
	backToLocalMatrix(2, 2) = 1;
	backToLocalMatrix(0, 2) = -this->renderObject->getPivot()[0];
	backToLocalMatrix(1, 2) = -this->renderObject->getPivot()[1];
	toOriginMatrix.print();
	scalingMatrix.print();
	backToLocalMatrix.print();

	scaleMatrix = toOriginMatrix * scalingMatrix * backToLocalMatrix;*/

	std::cout << "----------------------------" << std::endl;
	this->scaleMatrix.print();

	for (Vector<double>& vertex : vertices)
	{
		vertex.push(1);
		Vector<double> temp = this->scaleMatrix * vertex;
		vertex[0] = temp[0];
		vertex[1] = temp[1];
		vertex[2] = temp[2];
		vertex.popBack();
	}
}

void Transform::positionTranslate(std::vector<Vector<double>>& vertices)
{
	positionMatrix = Matrix<double>(4, 4);
	positionMatrix(0, 0) = 1;
	positionMatrix(1, 1) = 1;
	positionMatrix(2, 2) = 1;
	positionMatrix(3, 3) = 1;
	positionMatrix(0, 3) = this->position[0];
	positionMatrix(1, 3) = this->position[1];
	positionMatrix(2, 3) = this->position[2];

	/*for (Vector<double>& vertex : vertices)
	{
		vertex.push(1);
		Vector<double> temp = positionMatrix * vertex;
		vertex[0] = temp[0];
		vertex[1] = temp[1];
		vertex.popBack();
	}*/

	Vector<double>& pivot = this->renderObject->getPivot();
	pivot.push(1);
	Vector<double> temp = positionMatrix * pivot;
	pivot[0] = temp[0];
	pivot[1] = temp[1];
	pivot[2] = temp[2];
	pivot.popBack();
}

void Transform::rotationTranslate(std::vector<Vector<double>>& vertices)
{
	Matrix<double> rotationMatrixX = Matrix<double>(4, 4);
	rotationMatrixX(0, 0) = 1;
	rotationMatrixX(1, 1) = std::cos(this->rotation[0]);
	rotationMatrixX(1, 2) = -std::sin(this->rotation[0]);
	rotationMatrixX(2, 1) = std::sin(this->rotation[0]);
	rotationMatrixX(2, 2) = std::cos(this->rotation[0]);
	rotationMatrixX(3, 3) = 1;

	Matrix<double> rotationMatrixY = Matrix<double>(4, 4);
	rotationMatrixY(0, 0) = std::cos(this->rotation[1]);
	rotationMatrixY(0, 2) = std::sin(this->rotation[1]);
	rotationMatrixY(1, 1) = 1;
	rotationMatrixY(2, 0) = -std::sin(this->rotation[1]);
	rotationMatrixY(2, 2) = std::cos(this->rotation[1]);
	rotationMatrixY(3, 3) = 1;

	Matrix<double> rotationMatrixZ = Matrix<double>(4, 4);
	rotationMatrixZ(0, 0) = std::cos(this->rotation[2]);
	rotationMatrixZ(0, 1) = -std::sin(this->rotation[2]);
	rotationMatrixZ(1, 0) = std::sin(this->rotation[2]);
	rotationMatrixZ(1, 1) = std::cos(this->rotation[2]);
	rotationMatrixZ(2, 2) = 1;
	rotationMatrixZ(3, 3) = 1;

	this->rotationMatrix = rotationMatrixX * rotationMatrixY * rotationMatrixZ;

	for (Vector<double>& vertex : vertices)
	{
		vertex.push(1);
		Vector<double> temp = this->rotationMatrix * vertex;
		vertex[0] = temp[0];
		vertex[1] = temp[1];
		vertex[2] = temp[2];
		vertex.popBack();
	}
}
