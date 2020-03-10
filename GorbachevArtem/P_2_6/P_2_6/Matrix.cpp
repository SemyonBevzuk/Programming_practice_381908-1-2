#include "Matrix.h"



Matrix::Matrix(int a, int b)
{
	m = a;
	n = b;
	try {
		if ((m < 0) || (n < 0))
			throw "Ошибка - число строк и столбцов не может быть отрицательным!";
		Elements.resize(m);
		for (int i = 0; i < m; i++)
			Elements[i].resize(n);
	}
	catch (const char* str) {
		cout << str << endl;
	}
}

Matrix::Matrix(const Matrix & Mat)
{
	*this = Mat;
}

Matrix::~Matrix()
{
}

Matrix & Matrix::operator=(const Matrix & Mat)
{
	m = Mat.m;
	n = Mat.n;
	Elements = Mat.Elements;
	return *this;
}

Matrix Matrix::operator+(const Matrix & Mat) const
{
	Matrix tmp(m, n);
	try {
		if ((m != Mat.m) || (n != Mat.n))
			throw "Ошибка - матрицы должны быть одинакового размера!";
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				tmp.Elements[i][j] = Elements[i][j] + Mat.Elements[i][j];
	}
	catch (const char* str) {
		cout << str << endl;
	}
	return tmp;
}

int & Matrix::operator()(int i, int j)
{
	try {
		if ((i < 1) || (i > m) || (j < 1) || (j > n))
			throw "Ошибка - выход за границы массива!";
		return Elements[i - 1][j - 1];
	}
	catch (const char* str) {
		cout << str << endl;
		int x = 0;
		return x;
	}
}

Matrix Matrix::transpose()
{
	Matrix T(n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			T(i, j) = (*this)(j, i);
	return T;
}

bool Matrix::IsDiagonallyDominant()
{
	try {
		if (m != n)
			throw "Ошибка - матрица должна быть квадратной!";
		int sum = 0;
		for (int i = 2; i <= m; i++)
			for (int j = 1; j < i; j++)
				sum += abs((*this)(i, j)) + abs((*this)(j, i));
		for (int i = 1; i <= m; i++)
			if (abs((*this)(i, i)) < sum)
				return false;
		return true;
	}
	catch (const char* str) {
		cout << str << endl;
		return false;
	}
}

Matrix Matrix::operator*(Matrix & Mat)
{
	try {
		if (n != Mat.m)
			throw "Ошибка - число столбцов 1-й матрицы должно совпадать с числом строк 2-й!";
		Matrix M(m, Mat.n);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= Mat.n; j++) {
				M(i, j) = 0;
				for (int k = 1; k <= n; k++)
					M(i, j) += (*this)(i, k) * Mat(k, j);
			}
		return M;
	}
	catch (const char* str) {
		cout << str << endl;
		return Matrix(0, 0);
	}
}

Matrix Matrix::operator*(int x)
{
	Matrix M(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			M(i, j) = (*this)(i, j) * x;
	return M;
}

ofstream & operator<<(ofstream & out, Matrix & Mat)
{
	out << Mat.m << endl << Mat.n << endl;
	for (int i = 1; i <= Mat.m; i++) {
		for (int j = 1; j <= Mat.n; j++)
			out << Mat(i, j) << " ";
		out << endl;
	}
	return out;
}

ifstream & operator>>(ifstream & in, Matrix & Mat)
{
	int m, n;
	in >> m >> n;
	Matrix M(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			in >> M(i, j);
	Mat = M;
	return in;
}

Matrix operator*(int x, Matrix & Mat)
{
	return Mat * x;
}
