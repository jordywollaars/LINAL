#include "RenderObject.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
	//Front
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

	////Side y- z-
	//offsetx = 400;
	//offsety = 0;

	//for (auto vertex : vertices)
	//{
	//	sf::CircleShape shape(1);
	//	sf::Color color(255, 255, 255, 255);
	//	shape.setFillColor(color);
	//	shape.setPosition(offsetx + this->pivot[2] + vertex[2], offsety + this->pivot[1] + vertex[1]);

	//	window.draw(shape);
	//}

	//for (auto edge : edges)
	//{
	//	sf::Vertex edgeLine[]{
	//		{
	//			sf::Vector2f(offsetx + this->pivot[2] + edge.getStart()[2], offsety + this->pivot[1] + edge.getStart()[1]),
	//			{255,255,255,255}
	//		},
	//		{
	//			sf::Vector2f(offsetx + this->pivot[2] + edge.getEnd()[2], offsety + this->pivot[1] + edge.getEnd()[1]),
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
	//	shape.setPosition(offsetx + this->pivot[0] + vertex[0], offsety + this->pivot[2] + vertex[2]);

	//	window.draw(shape);
	//}

	//for (auto edge : edges)
	//{
	//	sf::Vertex edgeLine[]{
	//		{
	//			sf::Vector2f(offsetx + this->pivot[0] + edge.getStart()[0], offsety + this->pivot[2] + edge.getStart()[2]),
	//			{255,255,255,255}
	//		},
	//		{
	//			sf::Vector2f(offsetx + this->pivot[0] + edge.getEnd()[0], offsety + this->pivot[2] + edge.getEnd()[2]),
	//			{255,255,255,255}
	//		}
	//	};
	//	window.draw(edgeLine, 2, sf::Lines);
	//}
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
