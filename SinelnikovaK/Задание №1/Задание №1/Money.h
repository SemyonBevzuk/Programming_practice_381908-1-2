#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
	int s;
	int rub;
	int kop;

public:
	Money();

	~Money();

	Money(double num);

	Money Add(const Money num);

	Money Sub(const Money num);

	Money Mul(const double num);

	Money Div(const double num);

	Money& operator= (const Money num);

	Money operator+ (const Money num);

	Money operator- (const Money num);

	Money operator* (const double num);

	Money operator/ (const double num);

	bool operator== (const Money num);

	bool operator!= (const Money num);

	bool operator> (const Money num);

	bool operator>= (const Money num);

	bool operator< (const Money num);

	bool operator<= (const Money num);

	void outPut();

	void inPut();
};
