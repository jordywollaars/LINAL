#pragma once

template<class Scalar>
struct Vector3 {
public:
	Scalar x = 0;
	Scalar y = 0;
	Scalar z = 1;

	Vector3(Scalar x = 0.0, Scalar y = 0.0, Scalar z = 0.0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	/*Vector2 operator+(Vector2 const& other) const {
		return { x + other.x, y + other.y };
	}

	Vector2& operator+=(Vector2 const& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-(Vector2 const& other) const {
		return { x - other.x, y - other.y };
	}

	Vector2& operator-=(Vector2 const& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator*(Vector2 const& other) const {
		return { x * other.x, y * other.y };
	}

	Vector2& operator*=(Vector2 const& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2 operator/(Vector2 const& other) const {
		return { x / other.x, y / other.y };
	}

	Vector2& operator/=(Vector2 const& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2 operator*(Scalar scalar) const {
		return { x * scalar, y * scalar };
	}

	Vector2& operator*=(Scalar scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2 operator/(Scalar scalar) const {
		return { x / scalar, y / scalar };
	}

	Vector2& operator/=(Scalar scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	Vector2& operator-=(Scalar scalar) {
		x -= scalar;
		y -= scalar;
		return *this;
	}

	Vector2& operator+=(Scalar scalar) {
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