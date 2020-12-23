#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

#include "Matrix.hpp"
#include "Edge.hpp"

class RenderObject : public GameObject
{
public:
	RenderObject() : GameObject(this) {}

	virtual void render(sf::RenderWindow& window);

	void setStarRenderObject()
	{
		vertices = std::vector<Vector3<double>>();
		edges = std::vector<Edge<double>>();

		vertices.push_back(Vector3<double>(-8.0, -256.0, -30.0));
		vertices.push_back(Vector3<double>(91.0, -140.0, -30.0));
		vertices.push_back(Vector3<double>(306.0, -140.0, -30.0));
		vertices.push_back(Vector3<double>(117.0, -10.0, -30.0));
		vertices.push_back(Vector3<double>(200, 200.0, -30.0));
		vertices.push_back(Vector3<double>(-5.0, 64.0, -30.0));
		vertices.push_back(Vector3<double>(-200.0, 200.0, -30.0));
		vertices.push_back(Vector3<double>(-136.0, -10.0, -30.0));
		vertices.push_back(Vector3<double>(-326.0, -140.0, -30.0));
		vertices.push_back(Vector3<double>(-81.0, -140.0, -30.0));

		vertices.push_back(Vector3<double>(-8.0, -256.0, 30.0));
		vertices.push_back(Vector3<double>(91.0, -140.0, 30.0));
		vertices.push_back(Vector3<double>(306.0, -140.0, 30.0));
		vertices.push_back(Vector3<double>(117.0, -10.0, 30.0));
		vertices.push_back(Vector3<double>(200, 200.0, 30.0));
		vertices.push_back(Vector3<double>(-5.0, 64.0, 30.0));
		vertices.push_back(Vector3<double>(-200.0, 200.0, 30.0));
		vertices.push_back(Vector3<double>(-136.0, -10.0, 30.0));
		vertices.push_back(Vector3<double>(-326.0, -140.0, 30.0));
		vertices.push_back(Vector3<double>(-81.0, -140.0, 30.0));

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

		//this->pivot = Vector3<double>(0, 0, 0);

		/*for (auto vertex : vertices)
		{
			vertex.print();
		}*/

		/*this->setPosition(Vector3<double>(200, 200, 200));
		this->setScale(Vector3<double>(0.5, 0.5, 0.5));

		this->setRotation(Vector3<double>(90, 0, 0));*/
		//this->pivot.print();
		//this->pivot.print();
	}

	void setShipRenderObject();
	void transform(Matrix<double> matrix);

	std::vector<Vector3<double>>& getVertices();
	Vector3<double>& getPivot();
private:
	std::vector<Vector3<double>> vertices;
	std::vector<Edge<double>> edges;

	Vector3<double> pivot;
};