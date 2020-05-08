#include <iostream>
using namespace std;
#include "Octal.h"


int main()
{
	Octal a(3), b(47), d, e;
	d = a + b;
	Octal tmp = a;
	a = e;
	e = tmp;

	//cout << "a = " << a << "b = " << b << "d = " << d << "e = " << e << endl;
	cout << "Verification completed!" << endl;
	system("pause");
}