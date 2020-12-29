#pragma once

#include "Edge.hpp"
#include <vector>
#include <iostream>

template<class Scalar>
struct Triangle {
public:
	Triangle(Edge<Scalar>& edgeOne, Edge<Scalar>& edgeTwo, Edge<Scalar>& edgeThree)
	{
		edges = std::vector<Edge<Scalar>>();

		edges.push_back(edgeOne);
		edges.push_back(edgeTwo);
		edges.push_back(edgeThree);
	}
	std::vector<Edge<Scalar>> edges;

	//std::vector<Edge<Scalar>> tessellate(Vector3<Scalar> center)
	//{
	//	std::vector<Edge<Scalar>> edgeCollection = std::vector<Edge<Scalar>>();

	//	Vector3<Scalar> newPoint1 = (edges[0].getStart() + edges[0].getEnd()) / 2;
	//	//newPoint1.normalize();

	//	Vector3<Scalar> newPoint2 = (edges[1].getStart() + edges[1].getEnd()) / 2;
	//	//newPoint2.normalize();

	//	Vector3<Scalar> newPoint3 = (edges[2].getStart() + edges[2].getEnd()) / 2;
	//	//newPoint3.normalize();

	//	edgeCollection.push_back(Edge<double>(newPoint1, newPoint2));
	//	edgeCollection.push_back(Edge<double>(newPoint2, newPoint3));
	//	edgeCollection.push_back(Edge<double>(newPoint3, newPoint1));

	//	/*edgeCollection.push_back(Edge<double>(newPoint1, edges[1].getStart()));
	//	edgeCollection.push_back(Edge<double>(edges[1].getStart(), newPoint2));
	//	edgeCollection.push_back(Edge<double>(newPoint2, newPoint1));

	//	edgeCollection.push_back(Edge<double>(newPoint2, edges[2].getStart()));
	//	edgeCollection.push_back(Edge<double>(edges[2].getStart(), newPoint3));
	//	edgeCollection.push_back(Edge<double>(newPoint3, newPoint2));

	//	edgeCollection.push_back(Edge<double>(newPoint3, edges[0].getStart()));
	//	edgeCollection.push_back(Edge<double>(edges[0].getStart(), newPoint1));
	//	edgeCollection.push_back(Edge<double>(newPoint1, newPoint3));*/

	//	return edgeCollection;
	//}
};