#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Matrix
{
private:
	int m; //Строки
	int n; //Столбцы
	vector <vector <int>> Elements; //Элементы
public:
	Matrix(int a = 0, int b = 0);
	Matrix(const Matrix& Mat);
	~Matrix();
	Matrix& operator=(const Matrix& Mat);
	Matrix operator+(const Matrix& Mat) const;
	int& operator()(int i, int j);
	friend ofstream& operator<<(ofstream& out, Matrix& Mat);
	friend ifstream& operator>>(ifstream& in, Matrix& Mat);
	Matrix transpose();
	bool IsDiagonallyDominant();
	Matrix operator*(Matrix& Mat);
	Matrix operator*(int x);
	friend Matrix operator*(int x, Matrix& Mat);
};