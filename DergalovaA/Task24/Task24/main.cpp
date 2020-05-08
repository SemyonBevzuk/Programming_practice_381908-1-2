#include <iostream>
using namespace std;
#include "Octal.h"

int main()
{
	//ofstream file;
	//file.open("input.txt");
	//file.close();

	Octal A, B(143), C, D(B), E, F;
	cout << "Enter the size and the number of F:" << endl;
	cin >> F;
	A = 34;
	E = A + B;
	C = B - A;
	cout << "A = " << A << "B = " << B << "C = B - A = " << C << "D = " << D << "E = " << E << "F = " << F;
	cout << "D == B ? " << (D == B) << endl << "E != B ? " << (E != B) << endl;
	cout << "F > A ? " << (F > A) << endl << "F < E ? " << (F < E) << endl;
	system("pause");
}