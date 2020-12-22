#pragma once

#include <iostream>

template<class Scalar>
struct Vector {
public:
	Vector(Scalar x, Scalar y)
	{
		vector = new Scalar[4];
		this->capacity = 4;
		this->current = 2;

		this->vector[0] = x;
		this->vector[1] = y;
	}
	Vector(unsigned int size = 1, bool full = false)
	{
		vector = new Scalar[size];
		this->capacity = size;
		this->current = 0;

		if (full)
		{
			this->current = size;
		}
	}

	void push(Scalar data)
	{
		if (current == capacity)
		{
			Scalar* temp = new Scalar[2 * this->capacity];

			for (int i = 0; i < this->capacity; i++)
			{
				temp[i] = vector[i];
			}
			delete[] vector;
			this->capacity *= 2;
			vector = temp;
		}

		vector[current] = data;
		current++;
	}
	void push(Scalar data, unsigned int index)
	{
		if (index == this->capacity)
		{
			push(data);
		}
		else
		{
			this->vector[index] = this->data;
		}
	}
	void popBack()
	{
		if (this->current > 0)
		{
			Scalar* temp = new Scalar[this->capacity];

			for (int i = 0; i < this->capacity - 1; i++)
			{
				temp[i] = vector[i];
			}
			this->capacity -= 1;
			vector = temp;

			current--;
		}
	}
	int size() const { return this->current; }
	int getCapacity() const { return this->capacity; }
	void print()
	{
		for (int i = 0; i < this->current; i++)
		{
			std::cout << vector[i] << " ";
		}
		std::cout << std::endl;
	}
	void resize(unsigned int n, Scalar val = NULL)
	{
		Scalar* temp = new Scalar[n];
		for (unsigned int i = 0; i < this->current; ++i)
		{
			temp[i] = this->vector[i];
		}
		for (unsigned int i = this->current; i < n; ++i)
		{
			temp[i] = val;
		}
		//delete[] vector;
		this->vector = temp;
		this->current = n;
	}

	Scalar& operator[](unsigned int index)
	{
		if (index >= this->current) {
			std::cout << "vector index out of bound, exiting";
			exit(0);
		}
		return this->vector[index];
	}

	Vector operator+(Vector const& other) const
	{
		Vector sum(this);
		unsigned int i;
		for (i = 0; i < current; i++)
		{
			sum[i] = this->vector[i] + other[i];
		}
		return sum;
	}

	Vector& operator+=(Vector other)
	{
		for (unsigned int i = 0; i < current; i++)
		{
			this->vector[i] += other[i];
		}
		return *this;
	}

	Vector operator-(Vector const& other) const
	{
		Vector subtract(this);
		unsigned int i;
		for (i = 0; i < current; i++)
		{
			subtract[i] = this->vector[i] - other[i];
		}
		return subtract;
	}

	Vector& operator-=(Vector other)
	{
		for (unsigned int i = 0; i < current; i++)
		{
			this->vector[i] -= other[i];
		}
		return *this;
	}

	Vector operator*(Vector const& other) const
	{
		Vector multiply(this);
		unsigned int i;
		for (i = 0; i < current; i++)
		{
			multiply[i] = this->vector[i] * other[i];
		}
		return multiply;
	}

	Vector& operator*=(Vector other)
	{
		for (unsigned int i = 0; i < current; i++)
		{
			this->vector[i] *= other[i];
		}
		return *this;
	}

	Vector operator/(Vector const& other) const
	{
		Vector divide(this);
		unsigned int i;
		for (i = 0; i < current; i++)
		{
			divide[i] = this->vector[i] / other[i];
		}
		return divide;
	}

	Vector& operator/=(Vector other)
	{
		for (unsigned int i = 0; i < current; i++)
		{
			this->vector[i] /= other[i];
		}
		return *this;
	}

	bool operator==(Vector const& other) const
	{
		for (int i = 0; i < this->current; i++)
		{
			if (this->arr[i] != other[i])
			{
				return false;
			}
		}

		return true;
	}

	/**
	*	Normalize this vector.
	*/
	void normalize()
	{
		Scalar length = this->length();
		if (length > 0)
		{
			for (int i = 0; i < this->current; i++)
			{
				this->arr[i] /= length;
			}
		}
	}

	/**
	*	Length of this vector.
	*/
	Scalar length()
	{
		Scalar temp = 0.0;
		for (int i = 0; i < this->current; i++)
		{
			temp += pow(this->arr[i], 2);
		}
		return sqrt(temp);
	}

private:
	Scalar* vector;
	unsigned int capacity;
	unsigned int current;
};