#include "Rational.h"

int Rational::NOD(int a, int b)
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

Rational::Rational()
{
	n = 0; m = 1;
}

Rational::Rational(int a, int b)
{
	try
	{
	if (b == 0)
		throw "Division to 0!";
	}
	catch (int b)
	{
		cout << "Division to 0!" << endl;
	}
	n = a; m = b;
	simplify();
	/*	try
	{
		if (b == 0)
			throw 0;
		n = a; m = b;
		simplify();
	}
	catch (int b)
	{
		cout << "Division to 0!" << endl;
	}
	*/
}

Rational::Rational(int x)
{
	n = x; m = 1;
}

Rational::Rational(const Rational& b)
{
	n = b.n;
	m = b.m;
}

Rational::~Rational()
{
}

Rational Rational::operator+(Rational& a) const
{
	Rational res;
	res.n = n * a.m + a.n*m;
	res.m = m * a.m;
	res.simplify();
	return res;
}
Rational Rational::operator-(Rational& a)  const
{
	Rational res;
	res.n = n * a.m - a.n*m;
	res.m = m * a.m;
	res.simplify();
	return res;
}
Rational Rational::operator*(Rational& a)
{
	n *= a.n;
	m *= a.m;
	simplify();
	return *this;
}
Rational Rational::operator/(Rational& a)
{
	n /= a.n;
	m /= a.m;
	simplify();
	return *this;
}

void Rational::simplify()
{
	if (m == 0) return;
	if (m < 0)
	{
		n *= -1;
		m *= -1;
	}
	int nod = NOD(n, m);
	n /= nod;
	m /= nod;
};

Rational &Rational::operator=(Rational& a)
{
	n = a.n;
	m = a.m;
	simplify();
	return *this;
}

bool Rational::operator==(const Rational& a)
{
	return (n == a.n && m == a.m);
}

bool Rational::operator!=(const Rational& a)
{
	return !(*this == a);
}

bool Rational::operator>(const Rational & a)
{
	return n * a.m > a.n * m;
}

bool Rational::operator<(const Rational & a)
{
	return n * a.m < a.n * m;
}

istream & operator>>(istream & in, Rational & a)
{
	int n, m;
	cin >> n >> m;
	Rational res(n, m);
	a = res;
	return in;
}

ostream & operator<<(ostream & out, const Rational & a)
{
	out << a.n << "/" << a.m << endl;
	return out;
}