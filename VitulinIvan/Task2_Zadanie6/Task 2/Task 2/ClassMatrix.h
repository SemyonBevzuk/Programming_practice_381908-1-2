#pragma once
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include <iostream>


using namespace std;

class MyMatrix
{
private:
	int m;
	int n; 
	vector <vector <int>> marix; 
public:
	MyMatrix(int a = 0, int b = 0);
	MyMatrix(const MyMatrix& Mat);
	~MyMatrix();
	MyMatrix& operator=(const MyMatrix& Mat);
	const MyMatrix operator+(const MyMatrix& Mat) const;
	int operator()(int i, int j) const;
	int& operator()(int i, int j);
	friend ofstream& operator<<(ofstream& out, MyMatrix& Mat);
	friend ifstream& operator>>(ifstream& in, MyMatrix& Mat);
	MyMatrix Transpose();
	bool DiagonalDominant();
	const MyMatrix operator*(const MyMatrix& Mat) const;
	const MyMatrix operator*(int x) const;
};