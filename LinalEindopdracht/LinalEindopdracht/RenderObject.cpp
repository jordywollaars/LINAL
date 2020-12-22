#include "RenderObject.hpp"

void RenderObject::render(sf::RenderWindow& window)
{
	for (auto vertex : vertices)
	{
		sf::CircleShape shape(1);
		sf::Color color(255, 255, 255, 255);
		shape.setFillColor(color);
		shape.setPosition(this->pivot[0] + vertex[0], this->pivot[1] + vertex[1]);

		window.draw(shape);
	}

	for (auto edge : edges)
	{
		sf::Vertex edgeLine[]{
			{
				sf::Vector2f(this->pivot[0] + edge.getStart()[0], this->pivot[1] + edge.getStart()[1]),
				{255,255,255,255}
			},
			{
				sf::Vector2f(this->pivot[0] + edge.getEnd()[0], this->pivot[1] + edge.getEnd()[1]),
				{255,255,255,255}
			}
		};
		window.draw(edgeLine, 2, sf::Lines);
	}
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
