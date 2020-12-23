#pragma once

//#include "Matrix.hpp"

template<class Scalar>
class Matrix;

template<class Scalar>
struct Vector3 {
public:
	Scalar x = 0;
	Scalar y = 0;
	Scalar z = 0;
	Scalar w = 1;

	Vector3(Scalar x = 0.0, Scalar y = 0.0, Scalar z = 0.0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

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
	
	/*Vector3 operator+(Vector3 const& other) const {
		return { x + other.x, y + other.y };
	}

	Vector3& operator+=(Vector3 const& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector3 operator-(Vector3 const& other) const {
		return { x - other.x, y - other.y };
	}

	Vector3& operator-=(Vector3 const& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector3 operator*(Vector3 const& other) const {
		return { x * other.x, y * other.y };
	}

	Vector3& operator*=(Vector3 const& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector3 operator/(Vector3 const& other) const {
		return { x / other.x, y / other.y };
	}

	Vector3& operator/=(Vector3 const& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector3 operator*(Scalar scalar) const {
		return { x * scalar, y * scalar };
	}

	Vector3& operator*=(Scalar scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector3 operator/(Scalar scalar) const {
		return { x / scalar, y / scalar };
	}

	Vector3& operator/=(Scalar scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	Vector3& operator-=(Scalar scalar) {
		x -= scalar;
		y -= scalar;
		return *this;
	}

	Vector3& operator+=(Scalar scalar) {
		x += scalar;
		y += scalar;
		return *this;
	}*/

	bool operator==(Vector3 const& other) const {
		return x == other.x && y == other.y && z = other.z;
	}

	/**
	*	Normalize this vector.
	*/
	void normalize() {
		Scalar length = this->length();
		if (length > 0) {
			x /= length;
			y /= length;
			z /= length;
		}
	}

	/**
	*	Length of this vector.
	*/
	Scalar length() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
};