﻿#include "Money.h"

Money::Money()
{
	s = 1;
	rub = 0;
	kop = 0;
}

Money::~Money()
{
	s = 1;
	rub = 0;
	kop = 0;
}

Money::Money(double num)
{
	if (num >= 0)
	{
		rub = (int)num;
		kop = (int)((num - rub + 0.0005) * 100);
		s = 1;
	}
	else
	{
		rub = -(int)num;
		kop = -(int)((num + rub - 0.0005) * 100);
		s = -1;
	}
}

Money Money::Add(const Money num)
{
	Money Result;
	int flag = (kop + num.kop) / 100;
	Result.kop = (kop + num.kop) % 100;
	Result.rub = rub + num.rub + flag;
	Result.s = s;

	return Result;
}

Money Money::Sub(const Money num)
{
	Money Result;
	int flag = 0;
	if (kop < num.kop)
	{
		flag = 1;
		Result.kop = 100 + kop - num.kop;
	}
	else
		Result.kop = kop - num.kop;
	if (rub >= num.rub + flag)
		Result.rub = rub - num.rub - flag;
	else
	{
		Result.s = -1;
		Result.rub = num.rub - rub;
		Result.kop = 100 - Result.kop;
	}

	return Result;
}

Money Money::Mul(const double num)
{
	Money Result;
	double _num = num;
	if (_num < 0)
	{
		Result.s = -s;
		_num = -_num;
	}
	else
		Result.s = s;
	int flag = (int)((kop * _num) / 100);
	Result.kop = (int)(kop * _num) % 100;
	Result.rub = (int)(rub * _num);
	Result.rub += Result.s * flag;

	return Result;
}

Money Money::Div(const double num)
{
	double tmp = (double)((long long)rub * s);
	if (tmp < 0)
		tmp -= kop / 100.0;
	else
		tmp += kop / 100.0;
	tmp /= num;

	Money Result(tmp);

	return Result;
}

Money& Money::operator= (const Money num)
{
	s = num.s;
	rub = num.rub;
	kop = num.kop;

	return *this;
}

Money Money::operator+ (const Money num)
{
	if (s == num.s)
	{
		Money* tmp = new Money(this->Add(num));
		return *tmp;
	}
	else if (s == 1)
	{
		Money* _num = new Money(num);
		_num->s = 1;
		Money* tmp = new Money(this->Sub(*_num));
		return *tmp;
	}
	else
	{
		Money* _num = new Money(num);
		Money* th = new Money(*this);
		th->s = 1;
		Money* tmp = new Money(_num->Sub(*th));
		return *tmp;
	}
}

Money Money::operator- (const Money num)
{
	if (s == 1)
	{
		if (s == num.s)
		{
			Money* tmp = new Money(this->Sub(num));
			return *tmp;
		}
		else
		{
			Money* tmp = new Money(this->Add(num));
			return *tmp;
		}
	}
	else
	{
		if (num.s == 1)
		{
			Money* tmp = new Money(this->Add(num));
			return *tmp;
		}
		else
		{
			Money* tmp = new Money(this->Sub(num));
			tmp->s *= -1;
			return *tmp;
		}
	}
}

Money Money::operator* (const double num)
{
	Money* tmp = new Money(this->Mul(num));
	return *tmp;
}

Money Money::operator/ (const double num)
{
	Money* tmp = new Money(this->Div(num));
	return *tmp;
}

bool Money::operator== (const Money num)
{
	return s == num.s && rub == num.rub && kop == num.kop;
}

bool Money::operator!= (const Money num)
{
	return s != num.s || rub != num.rub || kop != num.kop;
}

bool Money::operator> (const Money num)
{
	if (s == num.s)
		if (s == 1)
			if (rub == num.rub)
				return kop > num.kop;
			else
				return rub > num.rub;
		else
			if (rub == num.rub)
				return kop < num.kop;
			else
				return rub < num.rub;
	else
		if (s == 1)
			return true;
		else
			return false;
}

bool Money::operator>= (const Money num)
{
	return *this > num || *this == num;
}

bool Money::operator< (const Money num)
{
	if (s == num.s)
		if (s == 1)
			if (rub == num.rub)
				return kop < num.kop;
			else
				return rub < num.rub;
		else
			if (rub == num.rub)
				return kop > num.kop;
			else
				return rub > num.rub;
	else
		if (s == -1)
			return true;
		else
			return false;
}

bool Money::operator<= (const Money num)
{
	return *this < num || *this == num;
}

void Money::outPut()
{
	if (s == 1)
		cout << '+';
	else
		cout << '-';
	cout << rub << '.';
	if (kop < 10)
		cout << '0' << kop;
	else
		cout << kop;
	cout << " p." << endl;
}

void Money::inPut()
{
	double num;
	cin >> num;
	if (num >= 0)
	{
		rub = (int)num;
		kop = (int)((num - rub + 0.0005) * 100);
		s = 1;
	}
	else
	{
		rub = -(int)num;
		kop = -(int)((num + rub - 0.0005) * 100);
		s = -1;
	}
}