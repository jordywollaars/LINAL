#pragma once

#include "RenderObject.hpp"

class Target : public RenderObject
{

private:
	int counter = 0;
	int counterTarget = 50;
	bool shrink = false;
public:
	void update() override;
};