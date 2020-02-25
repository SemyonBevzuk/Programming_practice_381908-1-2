#include <iostream>
#include <locale>
#include <string>
#include"Time.h"

using namespace std;


int main()
{
	Time c("02:01:03"), a(15, 59, 22), b(3, 5, 7);
	cout << b + a + c << "\n";
	Time d;
	d.setTime(1, 2, 3);
	a.setTime(1, 1, 1);
	b.setTime(2, 2, 2);
	cout << a * b * d;
	d.addHour(1);
	b.addMin(1);
	a.addSec(1);
	cout << d << "\n" << b << "\n" << a << "\n";
	cout << d.getHour();
}