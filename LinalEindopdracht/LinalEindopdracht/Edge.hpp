#pragma once

#include "Vector.hpp"

template<class Scalar>
struct Edge {
public:
	Edge(Vector<Scalar>& start, Vector<Scalar>& end) : start{ start }, end{ end }
	{
	}

	Vector<Scalar>& getStart()
	{
		return this->start;
	}
	Vector<Scalar>& getEnd()
	{
		return this->end;
	}
private:
	Vector<Scalar>& start;
	Vector<Scalar>& end;
};