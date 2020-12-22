#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

//#include "Vector.hpp"
#include "Edge.hpp"

class RenderObject : public GameObject
{
public:
	RenderObject() : GameObject(this) {}

	virtual void render(sf::RenderWindow& window);

	void setStarRenderObject()
	{
		vertices = std::vector<Vector<double>>();
		edges = std::vector<Edge<double>>();

		vertices.push_back(Vector<double>(-8.0, -256.0));
		vertices.push_back(Vector<double>(91.0, -140.0));
		vertices.push_back(Vector<double>(306.0, -140.0));
		vertices.push_back(Vector<double>(117.0, -10.0));
		vertices.push_back(Vector<double>(200, 200.0));
		vertices.push_back(Vector<double>(-5.0, 64.0));
		vertices.push_back(Vector<double>(-200.0, 200.0));
		vertices.push_back(Vector<double>(-136.0, -10.0));
		vertices.push_back(Vector<double>(-326.0, -140.0));
		vertices.push_back(Vector<double>(-81.0, -140.0));

		edges.push_back(Edge<double>(vertices[0], vertices[1]));
		edges.push_back(Edge<double>(vertices[1], vertices[2]));
		edges.push_back(Edge<double>(vertices[2], vertices[3]));
		edges.push_back(Edge<double>(vertices[3], vertices[4]));
		edges.push_back(Edge<double>(vertices[4], vertices[5]));
		edges.push_back(Edge<double>(vertices[5], vertices[6]));
		edges.push_back(Edge<double>(vertices[6], vertices[7]));
		edges.push_back(Edge<double>(vertices[7], vertices[8]));
		edges.push_back(Edge<double>(vertices[8], vertices[9]));
		edges.push_back(Edge<double>(vertices[9], vertices[0]));

		this->pivot.push(400);
		this->pivot.push(300);

		//this->setPosition(Vector2<double>(100, 100));
		this->setScale(Vector2<double>(2, 2));
	}

	std::vector<Vector<double>>& getVertices();
	Vector<double>& getPivot();
private:
	std::vector<Vector<double>> vertices;
	std::vector<Edge<double>> edges;

	Vector<double> pivot;
};