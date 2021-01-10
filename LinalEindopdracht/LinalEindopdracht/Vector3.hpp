#pragma once

//#include "Matrix.hpp"
#include <iostream>

template<class Scalar>
class Matrix;

template<class Scalar>
struct Vector3 {
public:
	Scalar x = 0;
	Scalar y = 0;
	Scalar z = 0;
	Scalar w = 1;

	Vector3(Scalar x = 0.0, Scalar y = 0.0, Scalar z = 0.0, Scalar w = 1.0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	/**
	*	recalculate Vector3 according to given matrix
	*/
	void transform(Matrix<Scalar> m)
	{
		double x = m(0, 0) * this->x + m(0, 1) * this->y + m(0, 2) * this->z + m(0, 3) * this->w;
		double y = m(1, 0) * this->x + m(1, 1) * this->y + m(1, 2) * this->z + m(1, 3) * this->w;
		double z = m(2, 0) * this->x + m(2, 1) * this->y + m(2, 2) * this->z + m(2, 3) * this->w;
		double w = m(3, 0) * this->x + m(3, 1) * this->y + m(3, 2) * this->z + m(3, 3) * this->w;

		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	/**
	*	Project Vector3 according to given matrix (This does not update the actual vector)
	*/
	Vector3 viewTransform(Matrix<Scalar> m)
	{
		Vector3<Scalar> projectionVector = Vector3<Scalar>();

		double x = m(0, 0) * this->x + m(0, 1) * this->y + m(0, 2) * this->z + m(0, 3) * this->w;
		double y = m(1, 0) * this->x + m(1, 1) * this->y + m(1, 2) * this->z + m(1, 3) * this->w;
		double z = m(2, 0) * this->x + m(2, 1) * this->y + m(2, 2) * this->z + m(2, 3) * this->w;
		double w = m(3, 0) * this->x + m(3, 1) * this->y + m(3, 2) * this->z + m(3, 3) * this->w;

		projectionVector.x = x;
		projectionVector.y = y;
		projectionVector.z = z;
		projectionVector.w = w;

		return projectionVector;
	}
	
	Vector3 operator+(Vector3 const& other) const {
		
		return Vector3<Scalar>( x + other.x, y + other.y , z + other.z, w + other.w);
	}

	Vector3 operator-(Vector3 const& other) const {
		return { x - other.x, y - other.y, z - other.z };
	}

	Vector3 operator*(Vector3 const& other) const {
		return { x * other.x, y * other.y, z * other.z };
	}

	Vector3 operator*(Scalar scalar) const {
		return { x * scalar, y * scalar, z * scalar };
	}
	Vector3& operator*=(Scalar scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	
	Vector3 operator/(Scalar scalar) const {
		return { x / scalar, y / scalar, z / scalar };
	}
	
	bool operator==(Vector3 const& other) const {
		return x == other.x && y == other.y && z = other.z;
	}

	void print()
	{
		std::cout << "-----Vector content-----" << std::endl;
		std::cout << "x: " << this->x << std::endl;
		std::cout << "y: " << this->y << std::endl;
		std::cout << "z: " << this->z << std::endl;
	}

	/**
	*	Normalize this vector.
	*/
	void normalize() {
		Scalar length = this->length();
		if (length > 0) {
			this->x /= length;
			this->y /= length;
			this->z /= length;
		}
	}

	/**
	*	Length of this vector.
	*/
	Scalar length() {
		return sqrt(x*x + y*y + z*z);
	}

	//inproduct
	static Scalar dotProduct(Vector3 v, Vector3 w) {
		double result;

		result += v.x * w.x;
		result += v.y * w.y;
		result += v.z * w.z;

		return result;
	}

	//uitproduct
	static Vector3<Scalar> crossProduct(Vector3 v, Vector3 w) {
		Vector3<Scalar> result;

		result.x = v.y * w.z - w.y * v.z;
		result.y = v.z * w.x - w.z * v.x;
		result.z = v.x * w.y - w.x * v.y;

		return result;
	}
};