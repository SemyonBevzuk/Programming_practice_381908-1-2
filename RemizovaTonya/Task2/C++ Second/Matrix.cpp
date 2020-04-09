#include "Matrix.h"
void Matrix::Create(int size)
{
	if (mat != nullptr)
	{
		this->~Matrix();
	}
	this->n = size;
	mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];
}

Matrix::Matrix()
{
	//Установленная
	Create(4);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}
}

Matrix::Matrix(int size)
{
	//Заданная
	Create(size);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}
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

void Matrix::Resize(int newsize)
{
	this->~Matrix();
	this->Create(newsize);
}

Matrix::~Matrix()
{
	//Очистка
	if (this->mat != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] this->mat[i];
		}
		delete[] this->mat;
	}
}

void Matrix::RandomM(int size)
{
	Resize(size);
	srand(time(NULL));
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
		Resize(other.n);
		for (int i = 0; i < n; i++)
		{
			this->mat[i] = other.mat[i];
		}
	}
	return*this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix res;
	res.Resize(other.n);
	if (this->n != other.n)
		throw -1;		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
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
	Matrix res;
	res.Resize(this->n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			res.mat[i][j] = mat[i][j] * scalar;
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& c)
{
	Matrix res;
	res.Resize(c.n);
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

istream& operator>> (istream& stream, Matrix c)
{
	c.Resize(c.n);
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
	Resize(this->n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			this->mat[i][j] = this->mat[j][i];
	}
	return *this;
}

bool Matrix::IsDiagonallyDominant()
{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(mat[i][i] > accumulate(mat[i], mat[i] + abs(n), 0) - mat[i][i]))
			a++;
	}
	if (a > 0)
		return true;
	else return false; 
}