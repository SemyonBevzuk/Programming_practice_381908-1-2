#include "Matrix.h"
void Matrix::Create(int size)
{
	if (mat != nullptr)
	{
		this->~Matrix();
	}
	n = size;
	mat = new int* [n];
	for (int i = 0; i < n; i++)
	{
	    mat[i] = new int[n];
	}
}

Matrix::Matrix()
{
	//Установленная
	Create(4);
}

Matrix::Matrix(int size)
{
	//Заданная
	Create(size);
}

Matrix::Matrix(const Matrix& other)
{
	//Копирование
	Create(other.n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
	}
}

Matrix::~Matrix()
{
	//Очистка
	if (mat != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}
	mat = nullptr;
}

void Matrix::RandomM(int size)
{
	Create(size);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = rand() % 9;
		}
	}
}


Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		Create(other.n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = other.mat[i][j];
			}
		}
	}
	return* this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix res(other.n);
	if (this->n != other.n)
		throw -1;		
	for (int i = 0; i < res.n; i++)
	{
		for (int j = 0; j < res.n; j++)
		{
			res.mat[i][j] = mat[i][j] + other.mat[i][j];
		}
	}
	return res;
}

int& Matrix::operator()(const int index1, const int index2)
{
	if (index1 - 1 >= n || index1 - 1 < 0 || index2 - 1 >= n || index2 - 1 < 0)
		throw - 1;
	return mat[index1 - 1][index2 - 1];
}

Matrix Matrix::operator*(int scalar)
{
	Matrix res(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			res.mat[i][j] = mat[i][j] * scalar;
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& c)
{
	Matrix res(c.n);
    if (this->n != c.n)
		throw -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res.mat[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				res.mat[i][j] += (mat[i][k] * c.mat[k][j]);
			}
		}
	}
	return res;
}

istream& operator>> (istream& stream, Matrix& c)
{
	stream >> c.n;
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			stream >> c.mat[i][j];
		}
	}
	return stream;
}

ostream& operator<< (ostream& stream, const Matrix& c)
{
	stream << c.n << " " << "\n";
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			stream << c.mat[i][j] << " ";
		}
		stream << "\n";
	}
	return stream;
}

Matrix Matrix::Trans()
{
	Matrix res(n);
	for (int i = 0; i < res.n; i++)
	{
		for (int j = 0; j < res.n; j++)
			res.mat[i][j] = this->mat[j][i];
	}
	return res;
}

bool Matrix::IsDiagonallyDominant()
{
	int a = 0;
	int l;
	bool IsDiagonallyDominant = true;
	for (int i = 0; i < n; i++)
	{
		l = 0;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			    l += abs(mat[i][j]);
		}
		if (abs(mat[i][i]) < l)
		{
			IsDiagonallyDominant = false;
			break;
		}
		if (abs(mat[i][i] > l))
			a++;
	}
	if (a == 0)
		IsDiagonallyDominant = false;
	return IsDiagonallyDominant;
}