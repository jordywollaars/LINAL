#include "BoundingBox.hpp"

BoundingBox::BoundingBox(std::vector<Vector3<double>>& vertices) : vertices{ vertices }
{
	updateBoundingBox();
}

void BoundingBox::updateBoundingBox()
{
	if (vertices.size() > 0)
	{
		this->minX = vertices[0].x;
		this->maxX = vertices[0].x;
		this->minY = vertices[0].y;
		this->maxY = vertices[0].y;
		this->minZ = vertices[0].z;
		this->maxZ = vertices[0].z;

		for (const auto vertex : vertices)
		{
			if (vertex.x > maxX)
			{
				maxX = vertex.x;
			}
			else if (vertex.x < minX)
			{
				minX = vertex.x;
			}

			if (vertex.y > maxY)
			{
				maxY = vertex.y;
			}
			else if (vertex.y < minY)
			{
				minY = vertex.y;
			}

			if (vertex.z > maxZ)
			{
				maxZ = vertex.z;
			}
			else if (vertex.z < minZ)
			{
				minZ = vertex.z;
			}
		}
	}
}

bool BoundingBox::collision(BoundingBox* b)
{
	Vector3<double> TopFrontLeft = Vector3<double>(this->minX, this->maxY, this->maxZ);
	Vector3<double> TopFrontRight = Vector3<double>(this->maxX, this->maxY, this->maxZ);

	Vector3<double> TopBackLeft = Vector3<double>(this->minX, this->maxY, this->minZ);
	Vector3<double> TopBackRight = Vector3<double>(this->maxX, this->maxY, this->minZ);

	Vector3<double> BottomFrontLeft = Vector3<double>(this->minX, this->minY, this->maxZ);
	Vector3<double> BottomFrontRight = Vector3<double>(this->maxX, this->minY, this->maxZ);

	Vector3<double> BottomBackLeft = Vector3<double>(this->minX, this->minY, this->minZ);
	Vector3<double> BottomBackRight = Vector3<double>(this->maxX, this->minY, this->minZ);

	if (b->isPointInsideAABB(TopFrontLeft) ||
		b->isPointInsideAABB(TopFrontRight) ||
		b->isPointInsideAABB(TopBackLeft) ||
		b->isPointInsideAABB(TopBackRight) ||
		b->isPointInsideAABB(BottomFrontLeft) ||
		b->isPointInsideAABB(BottomFrontRight) ||
		b->isPointInsideAABB(BottomBackLeft) ||
		b->isPointInsideAABB(BottomBackRight))
	{
		this->onCollision(b);
		b->onCollision(this);
		return true;
	}

	return false;
}

bool BoundingBox::isPointInsideAABB(Vector3<double> point)
{
	return (point.x >= minX && point.x <= maxX) &&
		(point.y >= minY && point.y <= maxY) &&
		(point.z >= minZ && point.z <= maxZ);
}