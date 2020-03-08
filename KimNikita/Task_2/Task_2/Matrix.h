#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

class Matrix {
private:
	int n;
	vector<vector<int>> mat;
public:
	Matrix() :n(0) {}
	Matrix(int size);
	Matrix(const Matrix&);
	Matrix(vector<vector<int>>);
	~Matrix() {};
	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator*=(int);
	const Matrix operator+(const Matrix&)const;
	const Matrix operator*(const Matrix&)const;
	const Matrix operator*(int)const;
	int& operator()(int, int);
	friend ifstream& operator>>(ifstream& in, Matrix& m);
	friend ofstream& operator<<(ofstream& out, Matrix& m);
	bool check_diagonal_dominant()const;
	const Matrix transpon();
};