#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

//#include "Vector.hpp"
#include "Edge.hpp"

class RenderObject : public GameObject
{
public:
	RenderObject() {}

	virtual void render(sf::RenderWindow& window);

	void setStarRenderObject()
	{
		vertices = std::vector<Vector<double>>();
		edges = std::vector<Edge<double>>();

		vertices.push_back(Vector<double>(392.0, 44.0));
		vertices.push_back(Vector<double>(491.0, 160.0));
		vertices.push_back(Vector<double>(706.0, 160.0));
		vertices.push_back(Vector<double>(517.0, 290.0));
		vertices.push_back(Vector<double>(600, 500.0));
		vertices.push_back(Vector<double>(395.0, 364.0));
		vertices.push_back(Vector<double>(200.0, 500.0));
		vertices.push_back(Vector<double>(264.0, 290.0));
		vertices.push_back(Vector<double>(74.0, 160.0));
		vertices.push_back(Vector<double>(319.0, 160.0));

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
	}
private:
	std::vector<Vector<double>> vertices;
	std::vector<Edge<double>> edges;
};