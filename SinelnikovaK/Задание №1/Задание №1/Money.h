#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
	char sign;
	int rub;
	int kop;

	Money Add(const Money& num);
	Money Sub(const Money& num);
	Money Mul(const double& num);
	Money Div(const double& num);

public:
	Money();
	Money(const Money& num);
	Money(double& num);
	~Money();

	Money& operator= (const Money& num);
	Money operator+ (const Money& num);
	Money operator- (const Money& num);
	Money operator* (const double& num);
	Money operator/ (const double& num);

	bool operator== (const Money& num);
	bool operator!= (const Money& num);
	bool operator> (const Money& num);
	bool operator>= (const Money& num);
	bool operator< (const Money& num);
	bool operator<= (const Money& num);

	friend ostream& operator<<(ostream& out, const Money& a);
	friend istream& operator>>(istream& in, Money& a);
};
;