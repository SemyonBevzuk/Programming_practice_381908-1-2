#include <iostream>
using namespace std;
#include "Rational.h"


int main()
{
	Rational a(3), b(4,8), c(-1), d, e;
	cout << "Initial values: a = 3; b = 4/8; c = -1, d and e are not set." << endl;
	d = a + b;
	cout << "Assign d the sum of a and b: " << endl;
	c = c * d;
	cout << "Assign c the result of multiplication of c and d" << endl;
	cout << "Set the value to e. Example: 4 5" << endl;
	cin >> e;
	cout << "If e > d, their values will be reversed." << endl;
	if (e > d)
	{
		Rational tmp = d;
		d = e;
		e = tmp;
	}

	cout << "a = " << a << "b = " << b << "c = " << c << "d = " << d << "e = " << e << endl;
	cout << "Verification completed!" << endl;
	system("pause");
}