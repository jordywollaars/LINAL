#include "RenderObject.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
	const double canvastWidth = 800;
	const double canvastHeight = 600;

	// middelpunt scherm
	int nulpuntCanvasX = canvastWidth / 2;
	int nulpuntCanvasY = canvastHeight / 2;

	// Afbeelden van de punten m�t perspectiefmatrix
	// cre�er perspectief matrix
	double near = 0.1;
	double far = 1000.0;
	double fovy = 60.0;
	double scale = near * std::tan(fovy * 0.5);

	Matrix<double> pm = Matrix<double>(4, 4);
	pm(0, 0) = scale;    
	pm(1, 1) = scale;   
	pm(2, 2) = -far / (far - near);        
	pm(2, 3) = -1;
	pm(3, 2) = -(far * near) / (far - near);

	Vector3<double> begin;
	Vector3<double> end;

	for (int i = 0; i < this->edges.size(); i++) {
		begin = this->edges[i].getStart().getPerspectiveCoordinate(pm);
		end = this->edges[i].getEnd().getPerspectiveCoordinate(pm);

		if ((begin.w > 0) && (end.w > 0)) {
				sf::Vertex edgeLine[]{
					{
						sf::Vector2f(nulpuntCanvasX + (int)(begin.x / begin.w * canvastWidth / begin.w), 
									 nulpuntCanvasY - (int)(begin.y / begin.w * canvastHeight / begin.w)),
						{255,255,255,255}
					},
					{
						sf::Vector2f(nulpuntCanvasX + (int)(end.x / end.w * canvastWidth / end.w),
									 nulpuntCanvasY - (int)(end.y / end.w * canvastHeight / end.w)),
						{255,255,255,255}
					}
				};
				window.draw(edgeLine, 2, sf::Lines);
		}
	}

	std::vector<sf::Color> colors{
		{255, 0, 0, 255},
		{ 0,255,0,255 },
		{ 0,0,255,255 },
	};

	for (int i = 1; i < 4; i++)
	{
		Vector3<double> center = this->getPivot();
		Vector3<double> origin = center + this->localAxis[0];
		Vector3<double> scaledUpAxis = this->localAxis[i] * 45;
		Vector3<double> dir = center + scaledUpAxis;

		begin = origin.getPerspectiveCoordinate(pm);
		end = dir.getPerspectiveCoordinate(pm);

		if ((begin.w > 0) && (end.w > 0)) {
			sf::Vertex edgeLine[]{
				{
					sf::Vector2f(nulpuntCanvasX + (int)(begin.x / begin.w * canvastWidth / begin.w),
								 nulpuntCanvasY - (int)(begin.y / begin.w * canvastHeight / begin.w)),
					colors[i-1]
				},
				{
					sf::Vector2f(nulpuntCanvasX + (int)(end.x / end.w * canvastWidth / end.w),
								 nulpuntCanvasY - (int)(end.y / end.w * canvastHeight / end.w)),
					colors[i - 1]
				}
			};
			window.draw(edgeLine, 2, sf::Lines);
		}
	}

	////Front
	//double offsetx = 0;
	//double offsety = 0;

	//for (auto vertex : vertices)
	//{
	//	sf::CircleShape shape(1);
	//	sf::Color color(255, 255, 255, 255);
	//	shape.setFillColor(color);
	//	shape.setPosition(offsetx + vertex.x, offsety + vertex.y);

	//	window.draw(shape);
	//}

	//for (auto edge : edges)
	//{
	//	sf::Vertex edgeLine[]{
	//		{
	//			sf::Vector2f(offsetx + edge.getStart().x, offsety + edge.getStart().y),
	//			{255,255,255,255}
	//		},
	//		{
	//			sf::Vector2f(offsetx + edge.getEnd().x, offsety + edge.getEnd().y),
	//			{255,255,255,255}
	//		}
	//	};
	//	window.draw(edgeLine, 2, sf::Lines);
	//}

	////Side y- z-
	//offsetx = 400;
	//offsety = 0;

	//for (auto vertex : vertices)
	//{
	//	sf::CircleShape shape(1);
	//	sf::Color color(255, 255, 255, 255);
	//	shape.setFillColor(color);
	//	shape.setPosition(offsetx + vertex.z, offsety + vertex.y);
	//
	//	window.draw(shape);
	//}

	//for (auto edge : edges)
	//{
	//	sf::Vertex edgeLine[]{
	//		{
	//			sf::Vector2f(offsetx + edge.getStart().z, offsety + edge.getStart().y),
	//			{255,255,255,255}
	//		},
	//		{
	//			sf::Vector2f(offsetx + edge.getEnd().z, offsety + edge.getEnd().y),
	//			{255,255,255,255}
	//		}
	//	};
	//	window.draw(edgeLine, 2, sf::Lines);
	//}

	//Top x-z-
	//offsetx = 150;
	//offsety = 250;

	//for (auto vertex : vertices)
	//{
	//	sf::CircleShape shape(1);
	//	sf::Color color(255, 255, 255, 255);
	//	shape.setFillColor(color);
	//	shape.setPosition(offsetx + vertex.x, offsety + vertex.z);
	//
	//	window.draw(shape);
	//}

	//for (auto edge : edges)
	//{
	//	sf::Vertex edgeLine[]{
	//		{
	//			sf::Vector2f(offsetx + edge.getStart().x, offsety + edge.getStart().z),
	//			{255,255,255,255}
	//		},
	//		{
	//			sf::Vector2f(offsetx + edge.getEnd().x, offsety + edge.getEnd().z),
	//			{255,255,255,255}
	//		}
	//	};
	//	window.draw(edgeLine, 2, sf::Lines);
	//}
}

void RenderObject::setShipRenderObject()
{
	vertices = std::vector<Vector3<double>>();
	edges = std::vector<Edge<double>>();

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

	double multiplier = 20;
	for (auto vertex : vertices)
	{
		vertex.x = vertex.x * multiplier;
		vertex.y = vertex.y * multiplier;
		vertex.z = vertex.z * multiplier;
		//vertex.print();
	}

	/*int pivotValue = 250;
	this->pivot.push(pivotValue);
	this->pivot.push(pivotValue);
	this->pivot.push(pivotValue);*/

	//this->setScale(Vector3<double>(0.5, 0.5, 0.5));

	//double angleInRadians = 90 * M_PI / 180;
	//this->setRotation(Vector3<double>(0, 0, angleInRadians));
	//this->pivot.print();
	//this->setPosition(Vector3<double>(100, 100, 100));
	//this->pivot.print();
}

void RenderObject::transform(Matrix<double> matrix)
{
	for (Vector3<double>& vertex : vertices)
	{
		vertex.transform(matrix);
	}

	/*for (Vector3<double>& dot : localAxis)
	{
		dot.transform(matrix);
	}*/

	pivot.transform(matrix);
}

std::vector<Vector3<double>>& RenderObject::getVertices()
{
	return this->vertices;
}

Vector3<double>& RenderObject::getPivot()
{
	double xTotal = 0;
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
		zTotal / vertices.size());

	return tdp;
}

Vector3<double> RenderObject::getLocalXAxis()
{
	Vector3<double> XAxis = Vector3<double>(
		vertices[0].x - vertices[1].x,
		vertices[0].y - vertices[1].y,
		vertices[0].z - vertices[1].z);

	return XAxis + this->getPivot();
}

Vector3<double> RenderObject::getLocalYAxis()
{
	Vector3<double> YAxis = Vector3<double>(
		vertices[0].x - vertices[2].x,
		vertices[0].y - vertices[2].y,
		vertices[0].z - vertices[2].z);

	return YAxis;
}

Vector3<double> RenderObject::getLocalZAxis()
{
	Vector3<double> ZAxis = Vector3<double>(
		vertices[0].x - vertices[3].x,
		vertices[0].y - vertices[3].y,
		vertices[0].z - vertices[3].z);

	return ZAxis;
}
