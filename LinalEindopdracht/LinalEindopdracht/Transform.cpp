#include "Transform.hpp"
#include "RenderObject.hpp"

void Transform::setScale(Vector3<double> scale)
{
	this->scale = Vector3<double>(scale.x, scale.y, scale.z);
}

void Transform::setPosition(Vector3<double> position)
{
	this->position = Vector3<double>(position.x, position.y, position.z);
}

void Transform::setRotation(Vector3<double> rotation)
{
	this->rotation = Vector3<double>(rotation.x, rotation.y, rotation.z);
}