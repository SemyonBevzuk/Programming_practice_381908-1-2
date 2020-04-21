#include "Matrix.h"

void Matrix::Create(int size)
{
	n = size;
	Matr = new int* [n];
	for (int i = 0; i < n; i++)
		Matr[i] = new int[n];
}

Matrix::Matrix(int _n, int elem)
{
	Create(_n);
	for (int i = 0; i < _n; i++)
		for (int j = 0; j < _n; j++)
			Matr[i][j] = elem;
}

Matrix::Matrix(const Matrix& matr)
{
	Create(matr.n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Matr[i][j] = matr.Matr[i][j];
}

Matrix::~Matrix()
{
	if (Matr != nullptr)
	{
		for (int i = 0; i < n; i++)
			delete[] Matr[i];
		delete[] Matr;
	}
	Matr = nullptr;
}

int& Matrix::operator()(int i, int j)
{
	if (i < n && j < n && i >= 0 && j >= 0)
		return Matr[i][j];
	else
		throw "The indexes are incorrect";
}

Matrix& Matrix::operator=(const Matrix& _matr)
{
	if (this != &_matr)
	{
		Create(_matr.n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				Matr[i][j] = _matr.Matr[i][j];
		}
	}
	return* this; 
}

Matrix Matrix::operator+(const Matrix& matr1)
{

	if (n == matr1.n)
	{
		Matrix matrRes(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrRes(i, j) = Matr[i][j] + matr1.Matr[i][j];
		return matrRes;
	}
	else
	{
		cout << "The matrixes have differet sizes" << endl;
		throw 1;
	}
}

Matrix Matrix::operator*(const Matrix& matr)
{
	if (n == matr.n)
	{
		Matrix matrRes(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a = 0;
				for (int k = 0; k < n; k++)
					a += Matr[i][k] * matr.Matr[k][j];
				matrRes(i, j) = a;
			}
		}
		return matrRes;
	}
	else
	{
		cout << "The matrixes have different sizes" << endl;
		throw 1;
	}
}

Matrix Matrix::operator*(int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Matr[i][j] *= x;
	return *this;
}

bool Matrix::IsDagonalDominance()
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++) 
		{
			if (i != j)
				sum += abs(Matr[i][j]);
		}
		if (abs(Matr[i][i] < sum))
			return false;
	}
	return true;
}

Matrix Matrix::Transpose()
{
	Matrix matrRes(n);
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
				matrRes.Matr[i][j] = Matr[j][i];
	return matrRes;
}

ofstream& operator<<(ofstream& ofstream, Matrix& _matr)
{
	for (int i = 0; i < _matr.n; i++)
	{
		for (int j = 0; j < _matr.n; j++)
			ofstream << _matr.Matr[i][j] << " ";
		ofstream << "\n";
	}
	return ofstream;
}

ifstream& operator>>(ifstream& ifstream, Matrix& _matr)
{
	_matr.Create(_matr.n);
	for (int i = 0; i < _matr.n; i++)
	{
		for (int j = 0; j < _matr.n; j++)
		{
			ifstream >> _matr.Matr[i][j];
		}
	}
	return ifstream;
}
