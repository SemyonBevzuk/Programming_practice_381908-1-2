#pragma once
#include <iostream>
using namespace std;
class Rational
{
private:
	int n, m;
public:
	Rational();
	Rational(int, int);
	Rational(int);
	Rational(const Rational&);
	~Rational();
	Rational& operator=(const Rational&);
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);
	bool operator==(const Rational&);
	bool operator!=(const Rational&);
	bool operator>(const Rational&);
	bool operator<(const Rational&);
	bool operator>=(const Rational&);
	bool operator<=(const Rational&);
	friend istream& operator>>(istream&, Rational&);
	friend ostream& operator<<(ostream&, const Rational&);
};