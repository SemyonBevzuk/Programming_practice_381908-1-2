#include <iostream>
#include <fstream>
#include"matrix.h"

int main()
{
	Matrix m(2, 2), n(2, 1);
	Matrix c = n + m;
	c(0,0) = 1;
	cout << c << "\n";
	cout << n * m;
	cout << "\n";
	cin >> c;
	c.Transposition();
	cout << c;
	cout << "\n";
	c(1, 1) = 10;
	c(0, 0) = 10;
	cout << c.Diag() << "\n";
	Matrix d(2, 2);
	d.MultiNum(2);
	cout << d;
}


