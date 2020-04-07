#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <fstream>
#include <ctime>
using namespace std;
class Matrix
{
private:
	int** mat; //two-dimensional dynamic array
	int n; //Size
	
public:

	//Constructors and destructor
	Matrix();//Default
	Matrix(int size);//Initializer
	Matrix(const Matrix& other);//Copy
	~Matrix();//Destructor
	
	//Secondary functions
	void Create(int size);//Matrix allocation
	void Resize(int newsize);//Matrix resizing
	void RandomM();//Random initialization
	void EnterFromKeyboard();
	
	//Operator overload
	Matrix& operator=(const Matrix& other);//Assignment operator overload
	Matrix operator+(const Matrix& other);//Addition operator overload
	int& operator()(const int index1, const int index2);//Index operator overload
	Matrix operator*(int scalar);//Overloading the operator of matrix multiplication by a scalar
	Matrix operator*(const Matrix& c);//Overloading matrix multiplication operation of two matrices
	friend istream& operator>> (istream& stream, Matrix c);//Overload operator output from the stream
	friend ostream& operator<< (ostream& stream, const Matrix& c);//Overload operator input into the stream

	//Methods
	void Trans(Matrix& newmat);//Transpose operation
	bool IsDiagonallyDominant();//Operation determining the presence of diagonal prevelance
};