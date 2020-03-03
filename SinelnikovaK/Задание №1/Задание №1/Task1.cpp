#include "Money.h"
using namespace std;

int main()
{
	Money x, y, z;

	cout << "Enter 2 numbers: ";
	x.inPut();
	y.inPut();

	z = x + y;
	z.outPut();

	z = x - y;
	z.outPut();

	z = x / 3.5;
	z.outPut();

	z = x * 3.5;
	z.outPut();

	if (x == y)
		cout << "x == y" << endl;

	if (x != y)
		cout << "x != y" << endl;

	if (x > y)
		cout << "x > y" << endl;

	if (x >= y)
		cout << "x >= y" << endl;

	if (x < y)
		cout << "x < y" << endl;

	if (x <= y)
		cout << "x <= y" << endl;

	return 0;
}