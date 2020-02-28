#pragma once
#include <iostream>
using namespace std;

class Rational {
private:

	int n, m;
	int NOD(int a, int b)
	{
		if (a < 0)
			a *= -1;
		while (a != b)
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	}

public:

	Rational();

	Rational(int a, int b);

	Rational(int x);

	Rational(const Rational& b);

	~Rational();

	Rational operator+(Rational& a);

	Rational operator-(Rational& a); 

	Rational operator*(Rational& a);

	Rational operator/(Rational& a);

	void simplify();

	Rational& operator=(Rational& a);

	bool operator==(const Rational& a);

	bool operator!=(const Rational& a);

	bool operator>(const Rational & a);

	bool operator<(const Rational & a);

	friend istream& operator>>(istream&, Rational&);

	friend ostream& operator<<(ostream&, const Rational&);
};