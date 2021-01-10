#pragma once

class RenderObject;

class GameObject
{
public:
	GameObject() {}

	virtual void update(double deltaTime) {};
};