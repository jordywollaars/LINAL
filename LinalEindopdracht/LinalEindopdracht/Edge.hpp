#pragma once

#include "Vector3.hpp"

template<class Scalar>
struct Edge {
public:
	Edge(Vector3<Scalar>& start, Vector3<Scalar>& end) : start{ start }, end{ end }
	{
	}

	Vector3<Scalar>& getStart()
	{
		return this->start;
	}
	Vector3<Scalar>& getEnd()
	{
		return this->end;
	}
private:
	Vector3<Scalar>& start;
	Vector3<Scalar>& end;
};