#include "Money.h"

Money::Money()
{
	sign = '+';
	rub = 0;
	kop = 0;
}

Money::Money(const Money& num)
{
	*this = num;
}

Money::Money(double& num)
{
	if (num >= 0)
	{
		rub = (int)num;
		kop = (int)((num - rub + 0.0005) * 100);
		sign = '+';
	}
	else
	{
		rub = -(int)num;
		kop = -(int)((num + rub - 0.0005) * 100);
		sign = '-';
	}
}

Money::~Money()
{
	sign = NULL;
	rub = 0;
	kop = 0;
}

Money Money::Add(const Money& num)
{
	Money Result;
	int flag = (kop + num.kop) / 100;
	Result.kop = (kop + num.kop) % 100;
	Result.rub = rub + num.rub + flag;
	Result.sign = sign;

	return Result;
}

Money Money::Sub(const Money& num)
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
		Result.sign = '-';
		Result.rub = num.rub - rub;
		Result.kop = 100 - Result.kop;
	}

	return Result;
}

Money Money::Mul(const double& num)
{
	Money Result;
	double _num = num;
	if (_num < 0)
	{
		if (sign == '+')
			Result.sign = '-';
		_num = -_num;
	}
	int flag = (int)((kop * _num) / 100);
	Result.kop = (int)(kop * _num) % 100;
	Result.rub = (int)(rub * _num);
	Result.rub += Result.sign * flag;

	return Result;
}

Money Money::Div(const double& num)
{
	double tmp = (double)rub + kop / 100.0;
	if (sign == '-')
		tmp = -tmp;
	tmp /= num;

	Money Result(tmp);

	return Result;
}

Money& Money::operator= (const Money& num)
{
	sign = num.sign;
	rub = num.rub;
	kop = num.kop;

	return *this;
}

Money Money::operator+ (const Money& num)
{
	if (sign == num.sign)
	{
		Money* tmp = new Money(this->Add(num));
		return *tmp;
	}
	else if (sign == '+')
	{
		Money* _num = new Money(num);
		_num->sign = '+';
		Money* tmp = new Money(this->Sub(*_num));
		return *tmp;
	}
	else
	{
		Money* _num = new Money(num);
		Money* th = new Money(*this);
		th->sign = '+';
		Money* tmp = new Money(_num->Sub(*th));
		return *tmp;
	}
}

Money Money::operator- (const Money& num)
{
	if (sign == '+')
	{
		if (sign == num.sign)
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
		if (num.sign == '+')
		{
			Money* tmp = new Money(this->Add(num));
			return *tmp;
		}
		else
		{
			Money _num = num;
			Money* tmp = new Money(_num.Sub(*this));
			return *tmp;
		}
	}
}

Money Money::operator* (const double& num)
{
	Money* tmp = new Money(this->Mul(num));
	return *tmp;
}

Money Money::operator/ (const double& num)
{
	Money* tmp = new Money(this->Div(num));
	return *tmp;
}

bool Money::operator== (const Money& num)
{
	return sign == num.sign && rub == num.rub && kop == num.kop;
}

bool Money::operator!= (const Money& num)
{
	return !(*this == num);
}

bool Money::operator> (const Money& num)
{
	if (sign == num.sign)
		if (sign == '+')
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
		if (sign == '+')
			return true;
		else
			return false;
}

bool Money::operator>= (const Money& num)
{
	return *this > num || *this == num;
}

bool Money::operator< (const Money& num)
{
	if (sign == num.sign)
		if (sign == '+')
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
		if (sign == '-')
			return true;
		else
			return false;
}

bool Money::operator<= (const Money& num)
{
	return *this < num || *this == num;
}

ostream& operator<<(ostream& out, const Money& a)
{
	out << a.sign;
	cout << a.rub << '.';
	if (a.kop < 10)
		out << '0';
	out << a.kop << " p." << endl;
	return out;
}

istream& operator>>(istream& in, Money& a)
{
	double num;
	in >> num;
	Money res;
	if (num >= 0)
	{
		res.rub = (int)num;
		res.kop = (int)((num - res.rub + 0.0005) * 100);
	}
	else
	{
		res.rub = -(int)num;
		res.kop = -(int)((num + res.rub - 0.0005) * 100);
		res.sign = '-';
	}
	a = res;
	return in;
}