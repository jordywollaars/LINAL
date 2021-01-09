#pragma once

#include "RenderObject.hpp"
#include "BoundingBox.hpp"

class Target : public RenderObject, public BoundingBox
{
private:
	double counter = 0;
	double counterTarget = .75;
	bool shrink = false;

	const double scaleSpeed = 15;
public:
	Target();
	void update(double deltaTime) override;
};