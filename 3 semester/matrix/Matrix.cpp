#include <iostream>
#include <sstream>
#include "Matrix.h"
using namespace std;

Matrix::~Matrix()
{
	for (int i_Rows = 0; i_Rows < n_Rows; i_Rows++)
	{
		delete[] matrix[i_Rows];
		matrix[i_Rows] = nullptr;
	}
	n_Rows = 0;
	n_Columns = 0;
	delete[] matrix;
	matrix = nullptr;
}

Matrix::Matrix(const Matrix& q)
{
	n_Rows = q.N_Rows();
	n_Columns = q.N_Columns();
	matrix = new int*[n_Rows];
	for (ptrdiff_t i_Rows = 0; i_Rows < n_Rows; i_Rows++)
	{
		matrix[i_Rows] = new int[n_Columns];
	}
	for (ptrdiff_t i_Rows = 0; i_Rows < n_Rows; i_Rows++)
	{
		for (ptrdiff_t j_Columns = 0; j_Columns < n_Columns; j_Columns++)
		{
			matrix[i_Rows][j_Columns] = q.matrix[i_Rows][j_Columns];
		}
	}
}

Matrix::Matrix(int n_Rows, int n_Columns)
{
	if ((n_Rows > 0) && (n_Columns > 0))
	{
		this->n_Rows = n_Rows;
		this->n_Columns = n_Columns;
		matrix = new int*[n_Rows];
		for (ptrdiff_t i_Rows = 0; i_Rows < n_Rows; i_Rows++)
		{
			matrix[i_Rows] = new int[n_Columns];
		}
		for (ptrdiff_t i_Rows = 0; i_Rows < n_Rows; i_Rows++)
		{
			for (ptrdiff_t j_Columns = 0; j_Columns < n_Columns; j_Columns++)
			{
				matrix[i_Rows][j_Columns] = 0;
			}
		}
	}
	else throw new exception("Невверно введены границы массива!");
}

Matrix::Matrix(int ** mat, int n_Rows, int n_Columns)
{
	if ((n_Rows > 0) && (n_Columns > 0))
	{
		this->n_Rows = n_Rows;
		this->n_Columns = n_Columns;
		matrix = mat;
	}
	else throw new exception("Невверно введены границы массива!");
}

void Matrix::Add(int mass[], ptrdiff_t n_Columns)
{
	if (this->n_Columns > n_Columns + 1)
	{
		for (int i_Columns = n_Columns; i_Columns+1 < this->n_Columns; i_Columns++)
		{
			matrix[i_Columns + 1] = matrix[i_Columns];
		}
		matrix[n_Columns] = mass;
	}
	else throw new exception("Невверно введены границы массива!");
}

Matrix& Matrix::operator+=(const Matrix & q1)
{
	if ((N_Rows() == q1.N_Rows()) && (N_Columns() == q1.N_Columns()))
	{
		for (int i_Rows = 0; i_Rows < N_Rows(); i_Rows++)
		{
			for (int i_Columns = 0; i_Columns < N_Columns(); i_Columns++)
			{
				matrix[i_Rows][i_Columns] += q1.matrix[i_Rows][i_Columns];
			}
		}
	}
	else throw new exception("Невозможно выполнить сложение");
	return *this;
}

Matrix & Matrix::operator-=(const Matrix & q1)
{
	if ((N_Rows() == q1.N_Rows()) && (N_Columns() == q1.N_Columns()))
	{
		for (int i_Rows = 0; i_Rows < N_Rows(); i_Rows++)
		{
			for (int i_Columns = 0; i_Columns < N_Columns(); i_Columns++)
			{
				matrix[i_Rows][i_Columns] -= q1.matrix[i_Rows][i_Columns];
			}
		}
	}
	else throw new exception("Невозможно выполнить вычитание");
	return *this;
}

Matrix & Matrix::operator*=(const Matrix & q1)
{
	int sum = 0;
	if (n_Rows = q1.N_Columns())
	{
		for (int i_Rows = 0; i_Rows < N_Rows(); i_Rows++)
		{
			for (int i_Columns = 0; i_Columns < N_Columns(); i_Columns++)
			{
				for (int ii_Columns = 0; ii_Columns < N_Columns(); ii_Columns++)
				{
					sum += matrix[i_Rows][ii_Columns] * q1.matrix[ii_Columns][i_Columns];
				}
				matrix[i_Rows][i_Columns] = sum;
				sum = 0;
			}
		}
	}
	else throw new exception("Невозможно выполнить умножение");
	return *this;
}

//std::ostream& Matrix::Write_to(std::ostream& ost) const
//{
//	for (int i_Rows = 0; i_Rows < n_Rows; i_Rows++)
//	{
//		for (int i_Columns = 0; i_Columns < n_Columns; i_Columns++)
//		{
//			ost << matrix[i_Rows][i_Columns] << " ";
//		}
//		ost << endl;
//	}
//	return ost;
//}
//
//std::iostream & Matrix::Read_from(std::iostream & ios)
//{
//	return ios;
//}

//double Matrix::Opredelitel(const Matrix & q1)
//{
//	if (n_Rows == n_Columns)
//	{
//		return 
//	}
//}

Matrix& operator+(const Matrix& q1, const Matrix& q2)
{
	Matrix q3(q1);
	q3 += q2;
	return q3;
}

Matrix& operator-(const Matrix& q1, const Matrix& q2)
{
	Matrix q3(q1);
	q3 -= q2;
	return q3;
}

Matrix& operator*(const Matrix& q1, const Matrix& q2)
{
	Matrix q3(q1);
	q3 *= q2;
	return q3;
}
