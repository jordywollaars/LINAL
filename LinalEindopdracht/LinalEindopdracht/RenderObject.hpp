#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

#include "Matrix.hpp"
#include "Edge.hpp"

class RenderObject : public GameObject
{
public:
	RenderObject() {
		vertices = std::vector<Vector3<double>>();
		edges = std::vector<Edge<double>>();

		localAxis = std::vector<Vector3<double>>{
			Vector3<double>{0, 0, 0},
			Vector3<double>{1, 0, 0},
			Vector3<double>{0, 1, 0},
			Vector3<double>{0, 0, 1}
		};
	}

	virtual void render(sf::RenderWindow& window);

	void setStarRenderObject();
	void setSphereRenderObject();
	void setShipRenderObject();
	void transformObject(Matrix<double> matrix);
	void transformVertices(Matrix<double> matrix);
	void rotateLocalAxis(Matrix<double> matrix);

	std::vector<Vector3<double>>& getVertices();
	std::vector<Edge<double>>& getEdges();
	Vector3<double>& getPivot();

	std::vector<Vector3<double>> getLocalAxis();
	Vector3<double> getLocalXAxis();
	Vector3<double> getLocalYAxis();
	Vector3<double> getLocalZAxis();
private:
	std::vector<Vector3<double>> vertices;
	std::vector<Edge<double>> edges;

	Vector3<double> pivot;
protected:
	std::vector<Vector3<double>> localAxis;
};