#include <iostream>
#include <cstdlib>
#include <fstream>
#include <clocale>
#include "ClassMatrix.h"

using namespace std;

int main() 
{
	setlocale(LC_CTYPE, " Russian");
	string str = "Поймана ошибка";
	MyMatrix A, B(3, 3),D, E, R, F,H;
	for (int i = 1; i <= 3; i++)
	{	for (int j = 1; j <= 3; j++)
		{
			B(i, j) = 10;
		}
	}
	MyMatrix C(B);
	ifstream is;
	is.open("MyMatrixI.txt");
	is >> A >> D >> E >> H;
	is.close();
	if (H.DiagonalDominant())
	{
		H = H.trs();
	}
	R = B + E;
	F = (E * 5)*C+B;
	D = A * D;
	ofstream os;
	os.open("MyMatrixO.txt");
	os << R << F << D << H;
	os.close();
}