#pragma once

#include "Vector.hpp"
#include <iostream>

//using namespace std;

template<class Scalar>
struct Matrix {
public:
	Matrix(unsigned int rowSize = 0, unsigned int colSize = 0, Scalar initial = Scalar())
	{
		this->rowSize = rowSize;
		this->colSize = colSize;
		matrix.resize(rowSize);
		for (unsigned int i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(colSize, initial);
		}
	}

	// Matrix Operations
	Matrix operator+(Matrix& other)
	{
		Matrix add(this->colSize, this->rowSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				add(i, j) = this->matrix[i][j] + other(i, j);
			}
		}

		return add;
	}

	Matrix operator-(Matrix& other)
	{
		Matrix subtracted(this->colSize, this->rowSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				subtracted(i, j) = this->matrix[i][j] - other(i, j);
			}
		}

		return subtracted;
	}

	Matrix operator*(Matrix& other)
	{
		Matrix multiply(this->rowSize, other.getColSize(), NULL);
		if (this->colSize == other.getRowSize())
		{
			unsigned i, j, k;
			Scalar temp = NULL;
			for (i = 0; i < this->rowSize; i++)
			{
				for (j = 0; j < other.getColSize(); j++)
				{
					temp = NULL;
					for (k = 0; k < this->colSize; k++)
					{
						temp += this->matrix[i][k] * other(k,j);
					}
					multiply(i, j) = temp;
				}
			}

			return multiply;
		}
		else
		{
			throw std::exception("Column size and others row size are not the same");
		}
	}

	//Matrix transpose();

	//Matrix-Vector Operations
	Vector<Scalar> operator*(Vector<Scalar>& other)
	{
		Vector<Scalar> multiply = Vector<Scalar>(other.size(), true);
		if (this->colSize == other.size())
		{
			unsigned i, j, k;
			Scalar temp = NULL;
			for (i = 0; i < this->rowSize; i++)
			{
				for (j = 0; j < other.size(); j++)
				{
					temp = NULL;
					for (k = 0; k < this->colSize; k++)
					{
						temp += this->matrix[i][k] * other[k];
					}
					multiply[i] = temp;
				}
			}

			return multiply;
		}
		else
		{
			throw std::exception("Column size and others row size are not the same");
		}
	}

	// Scalar Operations
	Matrix operator+(Scalar scalar)
	{
		Matrix result(this->rowSize, this->colSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				result(i, j) = this->m_matrix[i][j] + scalar;
			}
		}
		return result;
	}

	Matrix operator-(Scalar scalar)
	{
		Matrix result(this->rowSize, this->colSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				result(i, j) = this->m_matrix[i][j] - scalar;
			}
		}
		return result;
	}

	Matrix operator*(Scalar scalar)
	{
		Matrix result(this->rowSize, this->colSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				result(i, j) = this->m_matrix[i][j] * scalar;
			}
		}
		return result;
	}

	Matrix operator/(Scalar scalar)
	{
		Matrix result(this->rowSize, this->colSize, NULL);
		unsigned i, j;
		for (i = 0; i < this->rowSize; i++)
		{
			for (j = 0; j < this->colSize; j++)
			{
				result(i, j) = this->m_matrix[i][j] / scalar;
			}
		}
		return result;
	}

	Scalar& operator()(const unsigned& row, const unsigned& col)
	{
		return this->matrix[row][col];
	}

	void print()
	{
		std::cout << "Matrix: " << std::endl;
		for (unsigned i = 0; i < this->rowSize; i++)
		{
			for (unsigned j = 0; j < this->colSize; j++)
			{
				std::cout << "[" << this->matrix[i][j] << "] ";
			}
			std::cout << std::endl;
		}
	}
	unsigned int getColSize() const
	{
		return this->colSize;
	}
	unsigned int getRowSize() const
	{
		return this->rowSize;
	}
private:
	unsigned int rowSize;
	unsigned int colSize;
	Vector<Vector<Scalar>> matrix;
};