#pragma once

#include <iostream>
#include <vector>

//using namespace std;

#define _USE_MATH_DEFINES // for C++
#include <math.h>

#include "Vector3.hpp"

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
						temp += this->matrix[i][k] * other(k, j);
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

	static Matrix getTranslationMatrix(Scalar tx, Scalar ty, Scalar tz)
	{
		Matrix<Scalar> matrix = Matrix<Scalar>(4, 4);
		matrix(0, 0) = 1;
		matrix(1, 1) = 1;
		matrix(2, 2) = 1;
		matrix(3, 3) = 1;
		matrix(0, 3) = tx;
		matrix(1, 3) = ty;
		matrix(2, 3) = tz;

		return matrix;
	}

	static Matrix getScalingMatrix(Scalar sx, Scalar sy, Scalar sz)
	{
		Matrix<Scalar> matrix = Matrix<Scalar>(4, 4);
		matrix(0, 0) = sx;
		matrix(1, 1) = sy;
		matrix(2, 2) = sz;
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixX(Scalar angleXDegree)
	{
		double a = angleXDegree / 180 * M_PI;

		Matrix<Scalar> matrix = Matrix<Scalar>(4, 4);
		matrix(0, 0) = 1;
		matrix(1, 1) = std::cos(a);
		matrix(1, 2) = -std::sin(a);
		matrix(2, 1) = std::sin(a);
		matrix(2, 2) = std::cos(a);
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixY(Scalar angleXDegree)
	{
		double a = angleXDegree / 180 * M_PI;

		Matrix<Scalar> matrix = Matrix<Scalar>(4, 4);
		matrix(0, 0) = std::cos(a);
		matrix(0, 2) = std::sin(a);
		matrix(1, 1) = 1;
		matrix(2, 0) = -std::sin(a);
		matrix(2, 2) = std::cos(a);
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixZ(Scalar angleXDegree)
	{
		double a = angleXDegree / 180 * M_PI;

		Matrix<Scalar> matrix = Matrix<Scalar>(4, 4);
		matrix(0, 0) = std::cos(a);
		matrix(0, 1) = -std::sin(a);
		matrix(1, 0) = std::sin(a);
		matrix(1, 1) = std::cos(a);
		matrix(2, 2) = 1;
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixM1(Vector3<Scalar> as)
	{
		Matrix<double> matrix = Matrix<double>(4, 4);

		double xz = std::sqrt(as.x * as.x + as.z * as.z);

		if (xz == 0.0)
		{
			matrix(0, 0) = 1;
			matrix(1, 1) = 1;
			matrix(2, 2) = 1;
			matrix(3, 3) = 1;
		}
		else
		{
			matrix(0, 0) = as.x / xz; //cos
			matrix(1, 1) = 1;
			matrix(0, 2) = as.z / xz; //sin
			matrix(2, 0) = -as.z / xz; //-sin
			matrix(2, 2) = as.x / xz; //cos
			matrix(3, 3) = 1;
		}
		return matrix;
	}

	static Matrix getRotationMatrixM2(Vector3<Scalar> as)
	{
		Matrix<double> matrix = Matrix<double>(4, 4);

		double xz = std::sqrt(as.x * as.x + as.z * as.z);
		double xyz = std::sqrt(as.x * as.x + as.y * as.y + as.z * as.z);

		matrix(0, 0) = xz / xyz;
		matrix(0, 1) = as.y / xyz;
		matrix(1, 0) = -as.y / xyz;
		matrix(1, 1) = xz / xyz;
		matrix(2, 2) = 1;
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixM4(Vector3<Scalar> as)
	{
		Matrix<double> matrix = Matrix<double>(4, 4);

		double xz = std::sqrt(as.x * as.x + as.z * as.z);
		double xyz = std::sqrt(as.x * as.x + as.y * as.y + as.z * as.z);

		matrix(0, 0) = xz / xyz;
		matrix(0, 1) = -as.y / xyz;
		matrix(1, 0) = as.y / xyz;
		matrix(1, 1) = xz / xyz;
		matrix(2, 2) = 1;
		matrix(3, 3) = 1;

		return matrix;
	}

	static Matrix getRotationMatrixM5(Vector3<Scalar> as)
	{
		Matrix<double> matrix = Matrix<double>(4, 4);

		double xz = std::sqrt(as.x * as.x + as.z * as.z);

		if (xz == 0.0)
		{
			matrix(0, 0) = 1;
			matrix(1, 1) = 1;
			matrix(2, 2) = 1;
			matrix(3, 3) = 1;
		}
		else
		{
			matrix(0, 0) = as.x / xz; //cos
			matrix(1, 1) = 1;
			matrix(0, 2) = -as.z / xz; //sin
			matrix(2, 0) = as.z / xz; //-sin
			matrix(2, 2) = as.x / xz; //cos
			matrix(3, 3) = 1;
		}
		return matrix;
	}
private:
	unsigned int rowSize;
	unsigned int colSize;
	std::vector<std::vector<Scalar>> matrix;
};