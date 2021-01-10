#pragma once

#include <vector>
#include "Vector3.hpp"

class BoundingBox
{
public:
	BoundingBox(std::vector<Vector3<double>>& vertices);
	void updateBoundingBox();

	bool collision(BoundingBox* b);
	bool isPointInsideAABB(Vector3<double> point);

	virtual void onCollision(BoundingBox* other) {}
	
private:
	std::vector<Vector3<double>>& vertices;

	double minX, maxX;
	double minY, maxY;
	double minZ, maxZ;
};