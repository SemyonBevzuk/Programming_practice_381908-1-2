#include<iostream>
#include<fstream>

using namespace std;

class Matrix
{
private:
	int** mat;
	int row;
	void Create();
public:
	Matrix(const Matrix& m);
	Matrix(int _row = 1, int _elem = 0);
	~Matrix();
	//Ìועמהû
	bool Diagonal();
	Matrix Transpos();
	Matrix operator*(const int x);
	Matrix operator+(const Matrix& m);
	Matrix operator*(const Matrix& m);
	Matrix& operator=(const Matrix& m);
	int& operator()(int i, int j);

	friend ostream& operator<<(ostream& ofstream, const Matrix& m);
	friend istream& operator>>(istream& ofstream, Matrix& m);
};