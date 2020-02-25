#include "Rational.h"


void Rational::simplify()
{
	for (int i = (n < m) ? n : m; i > 1; i--)
		if ((n % i == 0) && (m % i == 0)) {
			n = n / i;
			m = m / i;
			simplify();
			break;
		}
}

Rational::Rational()
{
	n = 0; m = 1;
}

Rational::Rational(int a, int b)
{
	if (b == 0) return;
	if (b < 0) {
		b *= -1;
		a *= -1;
	}
	int x = (a < 0) ? -1 : 1;
	a *= x;
	n = a; m = b;
	simplify();
	n = n * x;
}

Rational::Rational(int x)
{
	n = x; m = 1;
}

Rational::Rational(const Rational& r)
{
	n = r.n;
	m = r.m;
}


Rational::~Rational()
{
}

Rational & Rational::operator=(const Rational & r)
{
	n = r.n;
	m = r.m;
	return *this;
}

Rational Rational::operator+(const Rational & r)
{
	int a1 = n, b1 = m;
	int a2 = r.n, b2 = r.m;
	a1 *= b2; a2 *= b1;
	int a = a1 + a2;
	int b = b1 * b2;
	return Rational(a, b);
}

Rational Rational::operator-(const Rational & r)
{
	int a1 = n, b1 = m;
	int a2 = r.n, b2 = r.m;
	a1 *= b2; a2 *= b1;
	int a = a1 - a2;
	int b = b1 * b2;
	return Rational(a, b);
}

Rational Rational::operator*(const Rational & r)
{
	int a = n * r.n, b = m * r.m;
	return Rational(a, b);
}

Rational Rational::operator/(const Rational & r)
{
	int a = n * r.m, b = m * r.n;
	return Rational(a, b);
}

Rational & Rational::operator+=(const Rational & r)
{
	*this = *this + r;
	return *this;
}

Rational & Rational::operator-=(const Rational & r)
{
	*this = *this - r;
	return *this;
}

Rational & Rational::operator*=(const Rational & r)
{
	*this = *this * r;
	return *this;
}

Rational & Rational::operator/=(const Rational & r)
{
	*this = *this / r;
	return *this;
}

bool Rational::operator==(const Rational & r)
{
	return n == r.n && m == r.m;
}

bool Rational::operator!=(const Rational & r)
{
	return !(*this == r);
}

bool Rational::operator>(const Rational & r)
{
	return n * r.m > r.n * m;
}

bool Rational::operator<(const Rational & r)
{
	return n * r.m < r.n * m;
}

bool Rational::operator>=(const Rational & r)
{
	return *this > r || *this == r;
}

bool Rational::operator<=(const Rational & r)
{
	return *this < r || *this == r;
}

istream & operator>>(istream & in, Rational & r)
{
	int a, b;
	scanf_s("%d/%d", &a, &b);
	Rational rin(a, b);
	r = rin;
	return in;
}

ostream & operator<<(ostream & out, const Rational & r)
{
	out << r.n << "/" << r.m;
	return out;
}

