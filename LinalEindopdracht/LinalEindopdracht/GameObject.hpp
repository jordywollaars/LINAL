#pragma once

#include "Transform.hpp"

class RenderObject;

class GameObject : public Transform
{
public:
	GameObject(RenderObject* renderObject = nullptr) : Transform(renderObject) {}

	virtual void update(double deltaTime) {};
};