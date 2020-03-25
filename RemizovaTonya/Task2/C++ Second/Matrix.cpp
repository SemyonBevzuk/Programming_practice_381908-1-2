#include "Matrix.h"
void Matrix::Create()
{
	mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];
}

Matrix::Matrix()
{
	//Установленная
	n = 4;
	Create();
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = rand() %9;
		}
	}
}

Matrix::Matrix(int size)
{
	//Заданная
	n = size;
	Create();
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = rand()%9;
		}
	}
}

//Matrix::~Matrix()
//{
//	//Очистка
//	delete[] this->mat;
//}

void Matrix::Print()
{
	cout << "Size matrix is " << n << "*" << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] / 10 > 0)
			{
				if (mat[i][j] / 100 > 0)
					cout << mat[i][j] << " ";
				else cout << mat[i][j] << "  ";
			}
			else cout << mat[i][j] << "   ";
		}
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	
	if (this->mat != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] this->mat[i];
		}
		delete[] this->mat;
	}

	this->n = other.n;

	this->mat = new int*[other.n];
	for (int i = 0; i < n; i++)
	{
		this->mat[i] = other.mat[i];
	}
	return*this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix res;
	for (int i = 0; i < res.n; i++)
	{
		delete[] res.mat[i];
	}
	delete[] res.mat;
	res.n = other.n;
	res.Create();
	
	if (this->n == other.n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				res.mat[i][j] = mat[i][j] + other.mat[i][j];
		}
	}
	else cout << "Matrices are not equal" << endl;
	return res;
}

int& Matrix::operator()(const int index1, const int index2)
{
	if (index1 - 1 >= n || index1 - 1 < 0 || index2 - 1 >= n || index2 - 1 < 0)
		cout << "Incorrect entry of indexes" << endl;
	else
	    cout << "Saerch element: " << mat[index1 - 1][index2 - 1] << endl;
    return mat[index1 - 1][index2 - 1];
}

Matrix Matrix::operator*(int scalar)
{
	Matrix res;
	for (int i = 0; i < res.n; i++)
	{
		delete[] res.mat[i];
	}
	delete[] res.mat;
	res.n = this->n;
	res.Create();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			res.mat[i][j] = mat[i][j] * scalar;
	}
	return res;
}

istream& operator>> (istream& stream, Matrix c)
{
	
	for (int i = 0; i < c.n; i++)
	{
		delete[] c.mat[i];
	}
	delete[] c.mat;
	c.Create();
	cout << "Size of Matix is " << c.n << "*" << c.n << endl;
	cout << "Matrix " << endl;
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			stream >> c.mat[i][j];
		}	
	}
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			cout << c.mat[i][j] << " ";
		}
		cout << endl;
	}
	return stream;
}

ostream& operator<< (ostream& stream, const Matrix& c)
{
	for (int i = 0; i < c.n; i++)
	{
		for (int j = 0; j < c.n; j++)
			stream << c.mat[i][j] << " ";
		stream << "\n";
	}
	return stream;
}

void Matrix::Trans(Matrix& trans)
{
	for (int i = 0; i < trans.n; i++)
	{
		delete[] trans.mat[i];
	}
	delete[] trans.mat;
	trans.n = this->n;
	trans.Create();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			trans.mat[i][j] = this->mat[j][i];
	}
	trans.Print();
}

void Matrix::CheckM()
{
	for (int i = 0; i < n; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
	cout << "Size of matrix is: " << n << endl;
	this->Create();
	cout << "Enter a matrix of this size" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
}

void Matrix::Diagonal()
{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(mat[i][i] > accumulate(mat[i], mat[i] + abs(n), 0) - mat[i][i]))
			a++;
	}
	if (a>0)
		cout << "Diagonal domiant matrix" << endl;
	else cout << "Matrix without diagonal prevalence" << endl;
}

Matrix Matrix::MultiplyM(Matrix& c1, Matrix& c2)
{
	if (c1.n == c2.n)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
		n = c1.n;
		Create();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					mat[i][j] += (c1.mat[i][k] * c2.mat[k][j]);
				}
			}
		}
	}
	else cout << "Matrix sizes don't match each other" << endl;
	return*this;
}