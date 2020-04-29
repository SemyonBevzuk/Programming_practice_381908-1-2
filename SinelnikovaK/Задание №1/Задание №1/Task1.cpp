#include "Money.h"
using namespace std;

int main()
{
	Money x, y, z;

	cout << "Enter 2 numbers: ";
	cin >> x;
	cin >> y;

	z = x + y;
	cout << z;

	z = x - y;
	cout << z;

	z = x / 3.5;
	cout << z;

	z = x * 3.5;
	cout << z;

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