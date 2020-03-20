#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class MyMatrix
{
private:
	int m;
	int n; 
	vector <vector <int>> Elt; 
public:
	MyMatrix(int a = 0, int b = 0);
	MyMatrix(const MyMatrix& Mat);
	~MyMatrix();
	MyMatrix& operator=(const MyMatrix& Mat);
	MyMatrix operator+(const MyMatrix& Mat) const;
	int& operator()(int i, int j);
	friend ofstream& operator<<(ofstream& out, MyMatrix& Mat);
	friend ifstream& operator>>(ifstream& in, MyMatrix& Mat);
	MyMatrix trs();
	bool DiagonalDominant();
	MyMatrix operator*(MyMatrix& Mat);
	MyMatrix operator*(int x);
};