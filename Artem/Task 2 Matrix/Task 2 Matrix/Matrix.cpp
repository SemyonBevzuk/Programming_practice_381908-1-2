#include "Matrix.h"

void Matrix::Create()
{
	Matr = new int* [n];
	for (int i = 0; i < n; i++)
		Matr[i] = new int[n];
}

void Matrix::Generate()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Matr[i][j];
}

Matrix::Matrix(int _n, int elem)
{
	n = _n;
	Create();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Matr[i][j] = elem;
}

Matrix::Matrix(const Matrix& matr)
{
	n = matr.n;
	Create();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Matr[i][j] = matr.Matr[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
		delete[] Matr[i];
	delete[] Matr;
	n = 0;
}

int& Matrix::operator()(int i, int j)
{
	if (i < n && j < n && i >= 0 && j >= 0)
		return Matr[i][j];
	else
		throw "The matrix is incorrect";
}

Matrix& Matrix::operator=(const Matrix& _matr)
{
	if (n == _matr.n)
	{
		for (int i = 0; i < n; i++)
			delete[] Matr[i];
		if (Matr != NULL)
			delete[] Matr;
		n = _matr.n;
		Create();
	}
	if (this == &_matr)
		return *this;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			Matr[i][j] = _matr.Matr[i][j];
	}
	return *this;
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
		cout << "Cannot be added." << endl;
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
		cout << "Cannot be multiplicated" << endl;
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

bool Matrix::IsDagonalDomination()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				sum += abs(Matr[i][j]);
	for (int i = 0; i < n; i++)
		if (abs(Matr[i][i]) < sum)
			return 0;
	return 1;
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
	_matr.Generate();
	for (int i = 0; i < _matr.n; i++)
	{
		for (int j = 0; j < _matr.n; j++)
		{
			ifstream >> _matr.Matr[i][j];
		}
	}
	return ifstream;
}
