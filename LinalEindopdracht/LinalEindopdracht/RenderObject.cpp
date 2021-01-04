#include "RenderObject.hpp"
#include "BoundingBox.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
}

void RenderObject::setSphereRenderObject(int levelOfDetail)
{
	vertices = std::vector<Vector3<double>>();
	edges = std::vector<Edge<double>>();

	vertices.push_back(Vector3<double>(1, 0, 0));
	vertices.push_back(Vector3<double>(-1, 0, 0));

	vertices.push_back(Vector3<double>(0, 1, 0));
	vertices.push_back(Vector3<double>(0, -1, 0));

	vertices.push_back(Vector3<double>(0, 0, 1));
	vertices.push_back(Vector3<double>(0, 0, -1));

	edges.push_back(Edge<double>(vertices[0], vertices[2]));
	edges.push_back(Edge<double>(vertices[2], vertices[4]));
	edges.push_back(Edge<double>(vertices[4], vertices[0]));

	edges.push_back(Edge<double>(vertices[0], vertices[3]));
	edges.push_back(Edge<double>(vertices[3], vertices[5]));
	edges.push_back(Edge<double>(vertices[5], vertices[0]));

	edges.push_back(Edge<double>(vertices[0], vertices[4]));
	edges.push_back(Edge<double>(vertices[4], vertices[2]));
	edges.push_back(Edge<double>(vertices[2], vertices[0]));

	edges.push_back(Edge<double>(vertices[0], vertices[5]));
	edges.push_back(Edge<double>(vertices[5], vertices[3]));
	edges.push_back(Edge<double>(vertices[3], vertices[0]));

	edges.push_back(Edge<double>(vertices[1], vertices[2]));
	edges.push_back(Edge<double>(vertices[2], vertices[5]));
	edges.push_back(Edge<double>(vertices[5], vertices[1]));

	edges.push_back(Edge<double>(vertices[1], vertices[3]));
	edges.push_back(Edge<double>(vertices[3], vertices[4]));
	edges.push_back(Edge<double>(vertices[4], vertices[1]));

	edges.push_back(Edge<double>(vertices[1], vertices[5]));
	edges.push_back(Edge<double>(vertices[5], vertices[2]));
	edges.push_back(Edge<double>(vertices[2], vertices[1]));

	edges.push_back(Edge<double>(vertices[3], vertices[1]));
	edges.push_back(Edge<double>(vertices[1], vertices[4]));
	edges.push_back(Edge<double>(vertices[4], vertices[3]));

	triangles.push_back(Triangle<double>(edges[0], edges[1], edges[2]));
	triangles.push_back(Triangle<double>(edges[3], edges[4], edges[5]));
	triangles.push_back(Triangle<double>(edges[6], edges[7], edges[8]));
	triangles.push_back(Triangle<double>(edges[9], edges[10], edges[11]));
	triangles.push_back(Triangle<double>(edges[12], edges[13], edges[14]));
	triangles.push_back(Triangle<double>(edges[15], edges[16], edges[17]));
	triangles.push_back(Triangle<double>(edges[18], edges[19], edges[20]));
	triangles.push_back(Triangle<double>(edges[21], edges[22], edges[23]));

	/*for (int i = 0; i < 1; i++)
	{
		std::vector<Edge<double>> theseEdges = std::vector<Edge<double>>();

		for (auto tri : triangles)
		{
			std::vector<Edge<double>> newEdges = tri.tessellate(this->getPivot());

			for (auto newEdge : newEdges)
			{
				theseEdges.push_back(newEdge);
			}
		}

		edges = std::vector<Edge<double>>(theseEdges);
	}*/
}

void RenderObject::setShipRenderObject()
{
	/*vertices = std::vector<Vector3<double>>();
	edges = std::vector<Edge<double>>();*/

	//Hull

	//Ring 1
	vertices.push_back(Vector3<double>(-0.620761, 0.148589, -4.603570));
	vertices.push_back(Vector3<double>(-0.620761, -0.148589, -4.603570));
	vertices.push_back(Vector3<double>(0.635302, 0.148589, -4.603570));
	vertices.push_back(Vector3<double>(0.635302, -0.148589, -4.603570));

	//Ring 2
	vertices.push_back(Vector3<double>(-0.806886, 0.275101, -1.718086));
	vertices.push_back(Vector3<double>(-0.806886, -0.370099, -1.745406));
	vertices.push_back(Vector3<double>(0.821426, 0.275101, -1.718086));
	vertices.push_back(Vector3<double>(0.821426, -0.370099, -1.745406));

	//Ring 3
	vertices.push_back(Vector3<double>(-0.838768, 0.503040, -1.283142));
	vertices.push_back(Vector3<double>(-0.838768, -0.408043, -1.255822));
	vertices.push_back(Vector3<double>(0.853308, 0.503040, -1.283142));
	vertices.push_back(Vector3<double>(0.853308, -0.408043, -1.255822));

	//Ring 4
	vertices.push_back(Vector3<double>(-0.947424, 0.537356, 0.412728));
	vertices.push_back(Vector3<double>(-0.947424, -0.537356, 0.412728));
	vertices.push_back(Vector3<double>(0.961964, 0.537356, 0.412728));
	vertices.push_back(Vector3<double>(0.961964, -0.537356, 0.412728));

	//Ring 5
	vertices.push_back(Vector3<double>(-0.947424, 0.591276, 1.108456));
	vertices.push_back(Vector3<double>(-0.947424, -0.591276, 1.108456));
	vertices.push_back(Vector3<double>(0.961964, 0.591276, 1.108456));
	vertices.push_back(Vector3<double>(0.961964, -0.591276, 1.108456));

	//Left Wing				 
	vertices.push_back(Vector3<double>(-3.178952, 0.087054, -0.193291));
	vertices.push_back(Vector3<double>(-3.178952, -0.087054, -0.193291));
	vertices.push_back(Vector3<double>(-0.992730, 0.399007, 3.688400));
	vertices.push_back(Vector3<double>(-0.992730, -0.399006, 3.688404));

	//Right Wing			 
	vertices.push_back(Vector3<double>(3.135330, 0.087054, -0.193291));
	vertices.push_back(Vector3<double>(3.135330, -0.087054, -0.193291));
	vertices.push_back(Vector3<double>(1.007270, 0.399007, 3.688404));
	vertices.push_back(Vector3<double>(1.007270, -0.399006, 3.688404));

	//Ring 1
	edges.push_back(Edge<double>(vertices[0], vertices[1]));
	edges.push_back(Edge<double>(vertices[0], vertices[2]));
	edges.push_back(Edge<double>(vertices[1], vertices[3]));
	edges.push_back(Edge<double>(vertices[2], vertices[3]));

	//Ring 2
	edges.push_back(Edge<double>(vertices[4], vertices[5]));
	edges.push_back(Edge<double>(vertices[4], vertices[6]));
	edges.push_back(Edge<double>(vertices[5], vertices[7]));
	edges.push_back(Edge<double>(vertices[6], vertices[7]));

	//Ring 3
	edges.push_back(Edge<double>(vertices[8], vertices[9]));
	edges.push_back(Edge<double>(vertices[8], vertices[10]));
	edges.push_back(Edge<double>(vertices[9], vertices[11]));
	edges.push_back(Edge<double>(vertices[10], vertices[11]));

	//Ring 4
	edges.push_back(Edge<double>(vertices[12], vertices[13]));
	edges.push_back(Edge<double>(vertices[12], vertices[14]));
	edges.push_back(Edge<double>(vertices[13], vertices[15]));
	edges.push_back(Edge<double>(vertices[14], vertices[15]));

	//Ring 5
	edges.push_back(Edge<double>(vertices[16], vertices[17]));
	edges.push_back(Edge<double>(vertices[16], vertices[18]));
	edges.push_back(Edge<double>(vertices[17], vertices[19]));
	edges.push_back(Edge<double>(vertices[18], vertices[19]));

	//Left Wing
	edges.push_back(Edge<double>(vertices[20], vertices[21]));
	edges.push_back(Edge<double>(vertices[20], vertices[22]));
	edges.push_back(Edge<double>(vertices[21], vertices[23]));
	edges.push_back(Edge<double>(vertices[22], vertices[23]));

	//Right Wing
	edges.push_back(Edge<double>(vertices[24], vertices[25]));
	edges.push_back(Edge<double>(vertices[24], vertices[26]));
	edges.push_back(Edge<double>(vertices[25], vertices[27]));
	edges.push_back(Edge<double>(vertices[26], vertices[27]));

	//Ring 1 - 2
	edges.push_back(Edge<double>(vertices[0], vertices[4]));
	edges.push_back(Edge<double>(vertices[1], vertices[5]));
	edges.push_back(Edge<double>(vertices[2], vertices[6]));
	edges.push_back(Edge<double>(vertices[3], vertices[7]));

	//Ring 2 - 3
	edges.push_back(Edge<double>(vertices[4], vertices[8]));
	edges.push_back(Edge<double>(vertices[5], vertices[9]));
	edges.push_back(Edge<double>(vertices[6], vertices[10]));
	edges.push_back(Edge<double>(vertices[7], vertices[11]));

	//Ring 3 - 4
	edges.push_back(Edge<double>(vertices[8], vertices[12]));
	edges.push_back(Edge<double>(vertices[9], vertices[13]));
	edges.push_back(Edge<double>(vertices[10], vertices[14]));
	edges.push_back(Edge<double>(vertices[11], vertices[15]));

	//Ring 4 - 5
	edges.push_back(Edge<double>(vertices[12], vertices[16]));
	edges.push_back(Edge<double>(vertices[13], vertices[17]));
	edges.push_back(Edge<double>(vertices[14], vertices[18]));
	edges.push_back(Edge<double>(vertices[15], vertices[19]));

	//Left Wing - Hull
	edges.push_back(Edge<double>(vertices[20], vertices[12]));
	edges.push_back(Edge<double>(vertices[21], vertices[13]));

	edges.push_back(Edge<double>(vertices[22], vertices[16]));
	edges.push_back(Edge<double>(vertices[23], vertices[17]));


	//Right Wing - Hull
	edges.push_back(Edge<double>(vertices[24], vertices[14]));
	edges.push_back(Edge<double>(vertices[25], vertices[15]));

	edges.push_back(Edge<double>(vertices[26], vertices[18]));
	edges.push_back(Edge<double>(vertices[27], vertices[19]));

	//double multiplier = 20;
	//for (auto vertex : vertices)
	//{
	//	vertex.x = vertex.x * multiplier;
	//	vertex.y = vertex.y * multiplier;
	//	vertex.z = vertex.z * multiplier;
	//	//vertex.print();
	//}

	this->pivot = Vector3<double>(0, 0, 0);

	//this->setScale(Vector3<double>(0.5, 0.5, 0.5));

	//double angleInRadians = 90 * M_PI / 180;
	//this->setRotation(Vector3<double>(0, 0, angleInRadians));
	//this->pivot.print();
	//this->setPosition(Vector3<double>(100, 100, 100));
	//this->pivot.print();
}

void RenderObject::transformObject(Matrix<double> matrix)
{
	for (Vector3<double>& vertex : vertices)
	{
		vertex.transform(matrix);
	}

	for (Vector3<double>& point : localAxis)
	{
		point.transform(matrix);
	}

	//pivot.transform(matrix);

	BoundingBox* temp = dynamic_cast<BoundingBox*>(this);
	if (temp)
	{
		temp->updateBoundingBox();
	}
}

void RenderObject::transformVertices(Matrix<double> matrix)
{
	for (Vector3<double>& vertex : vertices)
	{
		vertex.transform(matrix);
	}
}

void RenderObject::rotateLocalAxis(Matrix<double> matrix)
{
	for (Vector3<double>& dot : this->localAxis)
	{
		dot.transform(matrix);
	}
}

std::vector<Vector3<double>>& RenderObject::getVertices()
{
	return this->vertices;
}

std::vector<Edge<double>>& RenderObject::getEdges()
{
	return this->edges;
}

Vector3<double>& RenderObject::getPivot()
{
	/*double xTotal = 0;
	double yTotal = 0;
	double zTotal = 0;

	for (int i = 0; i < vertices.size(); i++) {
		xTotal += vertices[i].x;
		yTotal += vertices[i].y;
		zTotal += vertices[i].z;
	}

	Vector3<double> tdp = Vector3<double>(
		xTotal / vertices.size(),
		yTotal / vertices.size(),
		zTotal / vertices.size());*/

	return this->localAxis[0];
}

std::vector<Vector3<double>> RenderObject::getLocalAxis()
{
	return this->localAxis;
}

Vector3<double> RenderObject::getLocalXAxis()
{
	Vector3<double> XAxis = Vector3<double>(
		this->localAxis[1].x - this->localAxis[0].x,
		this->localAxis[1].y - this->localAxis[0].y,
		this->localAxis[1].z - this->localAxis[0].z);
	//XAxis.normalize();

	return XAxis;
}

Vector3<double> RenderObject::getLocalYAxis()
{
	Vector3<double> YAxis = Vector3<double>(
		this->localAxis[2].x - this->localAxis[0].x,
		this->localAxis[2].y - this->localAxis[0].y,
		this->localAxis[2].z - this->localAxis[0].z);
	//YAxis.normalize();

	return YAxis;
}

Vector3<double> RenderObject::getLocalZAxis()
{
	Vector3<double> ZAxis = Vector3<double>(
		this->localAxis[3].x - this->localAxis[0].x,
		this->localAxis[3].y - this->localAxis[0].y,
		this->localAxis[3].z - this->localAxis[0].z);

	//ZAxis.normalize();

	return ZAxis;
}
