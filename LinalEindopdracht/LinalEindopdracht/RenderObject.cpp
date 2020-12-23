#include "RenderObject.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
	//Front y-x-
	double offsetx = 0;
	double offsety = 0;

	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(offsetx + this->pivot[0] + vertex[0], offsety + this->pivot[1] + vertex[1]);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + this->pivot[0] + edge.getStart()[0], offsety + this->pivot[1] + edge.getStart()[1]),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + this->pivot[0] + edge.getEnd()[0], offsety + this->pivot[1] + edge.getEnd()[1]),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}

	//Side y-z-
	offsetx = 300;
	offsety = 0;

	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(offsetx + this->pivot[2] + vertex[2], offsety + this->pivot[1] + vertex[1]);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + this->pivot[2] + edge.getStart()[2], offsety + this->pivot[1] + edge.getStart()[1]),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + this->pivot[2] + edge.getEnd()[2], offsety + this->pivot[1] + edge.getEnd()[1]),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}

	//Top x-z-
	offsetx = 150;
	offsety = 250;

	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(offsetx + this->pivot[0] + vertex[0], offsety + this->pivot[2] + vertex[2]);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + this->pivot[0] + edge.getStart()[0], offsety + this->pivot[2] + edge.getStart()[2]),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + this->pivot[0] + edge.getEnd()[0], offsety + this->pivot[2] + edge.getEnd()[2]),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}
}

void RenderObject::setShipRenderObject()
{
	vertices = std::vector<Vector<double>>();
	edges = std::vector<Edge<double>>();

	//Hull

	//Ring 1
	vertices.push_back(Vector<double>(-0.620761, 0.148589, -4.603570));
	vertices.push_back(Vector<double>(-0.620761, -0.148589, -4.603570));
	vertices.push_back(Vector<double>(0.635302, 0.148589, -4.603570));
	vertices.push_back(Vector<double>(0.635302, -0.148589, -4.603570));

	//Ring 2
	vertices.push_back(Vector<double>(-0.806886, 0.275101, -1.718086));
	vertices.push_back(Vector<double>(-0.806886, -0.370099, -1.745406));
	vertices.push_back(Vector<double>(0.821426, 0.275101, -1.718086));
	vertices.push_back(Vector<double>(0.821426, -0.370099, -1.745406));

	//Ring 3
	vertices.push_back(Vector<double>(-0.838768, 0.503040, -1.283142));
	vertices.push_back(Vector<double>(-0.838768, -0.408043, -1.255822));
	vertices.push_back(Vector<double>(0.853308, 0.503040, -1.283142));
	vertices.push_back(Vector<double>(0.853308, -0.408043, -1.255822));

	//Ring 4
	vertices.push_back(Vector<double>(-0.947424, 0.537356, 0.412728));
	vertices.push_back(Vector<double>(-0.947424, -0.537356, 0.412728));
	vertices.push_back(Vector<double>(0.961964, 0.537356, 0.412728));
	vertices.push_back(Vector<double>(0.961964, -0.537356, 0.412728));

	//Ring 5
	vertices.push_back(Vector<double>(-0.947424, 0.591276, 1.108456));
	vertices.push_back(Vector<double>(-0.947424, -0.591276, 1.108456));
	vertices.push_back(Vector<double>(0.961964, 0.591276, 1.108456));
	vertices.push_back(Vector<double>(0.961964, -0.591276, 1.108456));

	//Left Wing
	vertices.push_back(Vector<double>(-3.178952, 0.087054, -0.193291));
	vertices.push_back(Vector<double>(-3.178952, -0.087054, -0.193291));
	vertices.push_back(Vector<double>(-0.992730, 0.399007, 3.688400));
	vertices.push_back(Vector<double>(-0.992730, -0.399006, 3.688404));

	//Right Wing
	vertices.push_back(Vector<double>(3.135330, 0.087054, -0.193291));
	vertices.push_back(Vector<double>(3.135330, -0.087054, -0.193291));
	vertices.push_back(Vector<double>(1.007270, 0.399007, 3.688404));
	vertices.push_back(Vector<double>(1.007270, -0.399006, 3.688404));

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
		vertex[0] = vertex[0] * multiplier;
		vertex[1] = vertex[1] * multiplier;
		vertex[2] = vertex[2] * multiplier;
		//vertex.print();
	}

	int pivotValue = 250;
	this->pivot.push(pivotValue);
	this->pivot.push(pivotValue);
	this->pivot.push(pivotValue);

	//this->setScale(Vector3<double>(0.5, 0.5, 0.5));

	//double angleInRadians = 90 * M_PI / 180;
	//this->setRotation(Vector3<double>(0, 0, angleInRadians));
	//this->pivot.print();
	//this->setPosition(Vector3<double>(100, 100, 100));
	//this->pivot.print();
}

std::vector<Vector<double>>& RenderObject::getVertices()
{
	return this->vertices;
}

Vector<double>& RenderObject::getPivot()
{
	this->pivot.print();
	return this->pivot;
}
