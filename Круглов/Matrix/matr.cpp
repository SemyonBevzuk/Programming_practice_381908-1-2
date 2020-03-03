#include"matrix.h"

//Конструкторы и деструкторы ----------------------------------------------
Matrix::Matrix()
{
	Row = 1;
	Create();
}

Matrix::Matrix(const Matrix& m)
{
	Row = m.Row;
	Create();
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			Matr[i][j] = m.Matr[i][j];
		}
	}
}

Matrix::Matrix(int _row)
{
	Row = _row;
	Create();
}

Matrix::Matrix(int _row, int elem)
{
	Row = _row;
	Create();
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			Matr[i][j] = elem;
		}
	}
}
Matrix :: ~Matrix()
{
	for (int i = 0; i < Row; i++)
		delete[] Matr[i];
	if (Matr != NULL)
		delete[] Matr;
	Row = 0;
}
//методы ---------------------------------------------------------------------


bool Matrix::Diag()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			if (j == i) continue;
			if (Matr[i][i] < Matr[i][j]) return 0;
		}
	}
	return 1;
}

void Matrix::MultiNum(int x)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			Matr[i][j] *= x;
		}
	}
}

void Matrix::Transposition()
{
	Matrix res(Row);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			res(j,i)=Matr[i][j];
		}
	}
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			Matr[i][j]=res(i,j);
		}
	}
	//~res;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m) return *this;
	Matrix res(m);
	return res;
}

Matrix Matrix::operator+(const Matrix& m)
{
	if (Row == m.Row)
	{
		Matrix res(Row);
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Row; j++)
			{
				res(i, j)= Matr[i][j] + m.Matr[i][j];
			}
		}
		return res;
	}
	else
	{
		throw "Matrixes have different range!!!";
	}
}

Matrix Matrix::operator*(const Matrix& m)
{
	if (Row==m.Row)
	{
		Matrix res(Row);
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Row; j++)
			{
				int x = 0;
				for (int k = 0; k < Row; k++)
					x+= Matr[i][k] * m.Matr[k][j];
				res(i, j)= x;
			}
			}
		return res;
	}
	else
	{
		cout << "Matrixes have different range!!!";
		exit(0);
	}
}

int& Matrix::operator()(int i, int j)
{
	if (i < Row && j < Row && i >= 0 && j >= 0)
		return Matr[i][j];
	else
		throw "Out of range!";
}
//ввод и вывод ----------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& ofstream, const Matrix& m)
{
	for (int i = 0; i < m.Row; i++)
	{
		for (int j = 0; j < m.Row; j++)
		{
			ofstream<< m.Matr[i][j]<<" ";
		}
		ofstream <<"\n";
	}
	return ofstream;
}

istream& operator>>(istream& ofstream, Matrix& m)
{
	for (int i = 0; i < m.Row; i++)
	{
		for (int j = 0; j < m.Row; j++)
		{
			ofstream >> m.Matr[i][j];
		}
	}
	return ofstream;
}
