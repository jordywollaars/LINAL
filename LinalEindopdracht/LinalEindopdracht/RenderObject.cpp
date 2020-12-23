#include "RenderObject.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
	const double canvastWidth = 800;
	const double canvastHeight = 600;

	// middelpunt scherm
	int nulpuntCanvasX = canvastWidth / 2;
	int nulpuntCanvasY = canvastHeight / 2;

	// Afbeelden van de punten mét perspectiefmatrix
	// creëer perspectief matrix
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

	////Top x- z-
	//offsetx = 0;
	//offsety = 300;

	//for (auto vertex : vertices)
	//{
	//	sf::CircleShape shape(1);
	//	sf::Color color(255, 255, 255, 255);
	//	shape.setFillColor(color);
	//	shape.setPosition(offsetx + vertex.x, offsety + vertex.z);

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

void RenderObject::transform(Matrix<double> matrix)
{
	for (Vector3<double>& vertex : vertices)
	{
		vertex.transform(matrix);
	}

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
