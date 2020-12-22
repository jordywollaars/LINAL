#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

//#include "Vector.hpp"
#include "Edge.hpp"

#define _USE_MATH_DEFINES // for C++
#include <math.h>

class RenderObject : public GameObject
{
public:
	RenderObject() : GameObject(this) {}

	virtual void render(sf::RenderWindow& window);

	void setStarRenderObject()
	{
		vertices = std::vector<Vector<double>>();
		edges = std::vector<Edge<double>>();

		vertices.push_back(Vector<double>(-8.0, -256.0, -30.0));
		vertices.push_back(Vector<double>(91.0, -140.0, -30.0));
		vertices.push_back(Vector<double>(306.0, -140.0, -30.0));
		vertices.push_back(Vector<double>(117.0, -10.0, -30.0));
		vertices.push_back(Vector<double>(200, 200.0, -30.0));
		vertices.push_back(Vector<double>(-5.0, 64.0, -30.0));
		vertices.push_back(Vector<double>(-200.0, 200.0, -30.0));
		vertices.push_back(Vector<double>(-136.0, -10.0, -30.0));
		vertices.push_back(Vector<double>(-326.0, -140.0, -30.0));
		vertices.push_back(Vector<double>(-81.0, -140.0, -30.0));

		vertices.push_back(Vector<double>(-8.0, -256.0, 30.0));
		vertices.push_back(Vector<double>(91.0, -140.0, 30.0));
		vertices.push_back(Vector<double>(306.0, -140.0, 30.0));
		vertices.push_back(Vector<double>(117.0, -10.0, 30.0));
		vertices.push_back(Vector<double>(200, 200.0, 30.0));
		vertices.push_back(Vector<double>(-5.0, 64.0, 30.0));
		vertices.push_back(Vector<double>(-200.0, 200.0, 30.0));
		vertices.push_back(Vector<double>(-136.0, -10.0, 30.0));
		vertices.push_back(Vector<double>(-326.0, -140.0, 30.0));
		vertices.push_back(Vector<double>(-81.0, -140.0, 30.0));

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

		edges.push_back(Edge<double>(vertices[10], vertices[11]));
		edges.push_back(Edge<double>(vertices[11], vertices[12]));
		edges.push_back(Edge<double>(vertices[12], vertices[13]));
		edges.push_back(Edge<double>(vertices[13], vertices[14]));
		edges.push_back(Edge<double>(vertices[14], vertices[15]));
		edges.push_back(Edge<double>(vertices[15], vertices[16]));
		edges.push_back(Edge<double>(vertices[16], vertices[17]));
		edges.push_back(Edge<double>(vertices[17], vertices[18]));
		edges.push_back(Edge<double>(vertices[18], vertices[19]));
		edges.push_back(Edge<double>(vertices[19], vertices[10]));

		edges.push_back(Edge<double>(vertices[0], vertices[10]));
		edges.push_back(Edge<double>(vertices[1], vertices[11]));
		edges.push_back(Edge<double>(vertices[2], vertices[12]));
		edges.push_back(Edge<double>(vertices[3], vertices[13]));
		edges.push_back(Edge<double>(vertices[4], vertices[14]));
		edges.push_back(Edge<double>(vertices[5], vertices[15]));
		edges.push_back(Edge<double>(vertices[6], vertices[16]));
		edges.push_back(Edge<double>(vertices[7], vertices[17]));
		edges.push_back(Edge<double>(vertices[8], vertices[18]));
		edges.push_back(Edge<double>(vertices[9], vertices[19]));

		this->pivot.push(200);
		this->pivot.push(200);
		this->pivot.push(200);

		for (auto vertex : vertices)
		{
			vertex.print();
		}

		//this->setRotation(90 * M_PI / 180);
		//this->pivot.print();
		//this->setPosition(Vector3<double>(100, 100, 100));
		this->setScale(Vector3<double>(0.5, 0.5, 0.5));
		//this->pivot.print();
	}

	std::vector<Vector<double>>& getVertices();
	Vector<double>& getPivot();
private:
	std::vector<Vector<double>> vertices;
	std::vector<Edge<double>> edges;

	Vector<double> pivot;
};