#include<iostream>
#include<fstream>

using namespace std;

class Matrix
{
private:
	int** Matr;
	int Row;

	void Create()
	{
		Matr = new int* [Row];
		for (int i = 0; i < Row; i++)
		{
			Matr[i] = new int[Row];
		}
	}

public:
	Matrix();
	Matrix(const Matrix& m);
	Matrix(int _row);
	Matrix(int _row, int _elem);
	~Matrix();
	//methods
	bool Diag();
	void MultiNum(int x);
	void Transposition();
	Matrix operator+(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix& operator=(const Matrix& m);
	int& operator()(int i, int j);
	
	friend ostream& operator<<(ostream& ofstream, const Matrix& m);
	friend istream& operator>>(istream& ofstream, Matrix& m);
};