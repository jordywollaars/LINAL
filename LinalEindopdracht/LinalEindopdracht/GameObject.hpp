#pragma once

#include "Transform.hpp"

class GameObject : public Transform
{
public:
	GameObject(){}

	virtual void update() {};
};