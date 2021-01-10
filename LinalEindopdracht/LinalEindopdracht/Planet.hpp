#pragma once

#include "RenderObject.hpp"
#include "BoundingBox.hpp"

class Planet : public RenderObject, public BoundingBox
{
public:
	Planet() : BoundingBox(this->getVertices()) {
		this->setSphereRenderObject();
	};
};