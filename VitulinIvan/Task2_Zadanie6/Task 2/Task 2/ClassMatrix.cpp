#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ClassMatrix.h"
#include <vector>
#include <fstream>

using namespace std;

MyMatrix::MyMatrix(int a, int b)
{
	m = a;
	n = b;
	try 
	{
		if ((m < 0) || (n < 0))
			throw exception ("Неверное число столбцов или строк");
		Elt.resize(m);
		for (int i = 0; i < m; i++)
		{
			Elt[i].resize(n);
		}
	}
	catch (const char* str) 
	{
		cout << str << endl;
	}
}

MyMatrix::MyMatrix(const MyMatrix& Mat)
{
	*this = Mat;
}

MyMatrix::~MyMatrix()
{
}

MyMatrix& MyMatrix::operator=(const MyMatrix& Mat)
{
	m = Mat.m;
	n = Mat.n;
	Elt = Mat.Elt;
	return *this;
}

MyMatrix MyMatrix::operator+(const MyMatrix& Mat) const
{
	MyMatrix tmp(m, n);
	try 
	{
		if ((m != Mat.m) || (n != Mat.n))
			throw exception ("Матрицы должны быть одного размера");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp.Elt[i][j] = Elt[i][j] + Mat.Elt[i][j];
			}
		}
	}
	catch (const char* str) 
	{
		cout << str << endl;
	}
	return tmp;
}

int& MyMatrix::operator()(int i, int j)
{
	try 
	{
		if ((i < 1) || (i > m) || (j < 1) || (j > n))
			throw exception ("Неверный индекс элемента");
		return Elt[i - 1][j - 1];
	}
	catch (const char* str) 
	{
		cout << str << endl;
		int x = 0;
		return x;
	}
}

MyMatrix MyMatrix::trs()
{
	MyMatrix T(n, m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			T(i, j) = (*this)(j, i);
		}
	}
	return T;
}

bool MyMatrix::DiagonalDominant()
{
	try 
	{
		if (m != n)
			throw exception ("Определить невозможно: матрица должна быть квадратной");
		int sum = 0;
		for (int i = 2; i <= m; i++)
		{
			for (int j = 1; j < i; j++)
			{
				sum += abs((*this)(i, j)) + abs((*this)(j, i));
			}
		}
		for (int i = 1; i <= m; i++)
		{
			if (abs((*this)(i, i)) < sum)
				return false;
		}
		return true;
	}
	catch (const char* str) 
	{
		cout << str << endl;
		return false;
	}
}

MyMatrix MyMatrix::operator*(MyMatrix& Mat)
{
	try 
	{
		if (n != Mat.m)
			throw exception ("Число строк одной матрицы и число столбцов другой матрицы должно совпадать");
		MyMatrix M(m, Mat.n);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= Mat.n; j++)
			{
				M(i, j) = 0;
				for (int k = 1; k <= n; k++)
				{
					M(i, j) += (*this)(i, k) * Mat(k, j);
				}
			}
		}
		return M;
	}
	catch (const char* str) 
	{
		cout << str << endl;
		return MyMatrix(0, 0);
	}
}

MyMatrix MyMatrix::operator*(int x)
{
	MyMatrix M(m, n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			M(i, j) = (*this)(i, j) * x;
		}
	}
	return M;
}

ofstream& operator<<(ofstream& out, MyMatrix& Mat)
{
	out << Mat.m << endl << Mat.n << endl;
	for (int i = 1; i <= Mat.m; i++) 
	{
		for (int j = 1; j <= Mat.n; j++)
		{
			out << Mat(i, j) << " ";
		}
		out << endl;
	}
	return out;
}

ifstream& operator>>(ifstream& in, MyMatrix& Mat)
{
	int m, n;
	in >> m >> n;
	MyMatrix M(m, n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			in >> M(i, j);
		}
	}
	Mat = M;
	return in;
}
