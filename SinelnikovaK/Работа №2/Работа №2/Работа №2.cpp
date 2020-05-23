#include "Decimal.h"

int main()
{
	Decimal a, b, c;
	cin >> a >> b;

	c = a + b;
	cout << "a + b = " << c << endl;

	c = a - b;
	cout << "a - b = " << c << endl;

	if (a == b)
		cout << "a == b" << endl;

	if (a != b)
		cout << "a != b" << endl;

	if (a > b)
		cout << "a > b" << endl;

	if (a < b)
		cout << "a < b" << endl;

	if (a >= c)
		cout << "a >= c" << endl;

	if (a <= c)
		cout << "a <= c" << endl;
}
