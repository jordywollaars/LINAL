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
		shape.setPosition(offsetx + vertex.x, offsety + vertex.y);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + edge.getStart().x, offsety + edge.getStart().y),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + edge.getEnd().x, offsety + edge.getEnd().y),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}

	//Side y- z-
	offsetx = 400;
	offsety = 0;

	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(offsetx + vertex.z, offsety + vertex.y);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + edge.getStart().z, offsety + edge.getStart().y),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + edge.getEnd().z, offsety + edge.getEnd().y),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}

	//Top x- z-
	offsetx = 0;
	offsety = 300;

	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(offsetx + vertex.x, offsety + vertex.z);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(offsetx + edge.getStart().x, offsety + edge.getStart().z),
				{255,255,255,255}
			},
			{
				sf::Vector2f(offsetx + edge.getEnd().x, offsety + edge.getEnd().z),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}
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
	return this->pivot;
}
