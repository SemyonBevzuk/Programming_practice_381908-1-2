#include "Decimal.h"

Decimal Decimal::add(const Decimal& num)
{
	Decimal Result;
	Result.size = max(size, num.size);
	Result.sign = sign;
	Result.arr = new unsigned char[Result.size + 1];

	for (int i = 0; i < size; i++)
		Result.arr[i] = arr[i];

	for (int i = size; i < Result.size + 1; i++)
		Result.arr[i] = 0;

	for (int i = 0; i < num.size; i++)
	{
		Result.arr[i + 1] += (Result.arr[i] + num.arr[i]) / 10;
		Result.arr[i] = (Result.arr[i] + num.arr[i]) % 10;
	}
	int i = num.size;
	while (Result.arr[i] > 9)
	{
		Result.arr[i] %= 10;
		Result.arr[++i]++;
	}
	if (Result.arr[Result.size] != 0)
		Result.size++;
	return Result;
}

Decimal Decimal::sub(const Decimal& num)
{
	Decimal Result = max(abs(*this), abs(num));
	if (Result == abs(*this))
		Result.sign = '+';
	else
		Result.sign = '-';
	Decimal tmp = min(abs(*this), abs(num));
	int f = 0;
	for (int i = 0; i < tmp.size; i++)
	{
		if (Result.arr[i] < tmp.arr[i] + f)
		{
			Result.arr[i] += 10 - tmp.arr[i] - f;
			f = 1;
		}
		else
		{
			Result.arr[i] -= tmp.arr[i] + f;
			f = 0;
		}
	}
	return Result;
}

Decimal::Decimal() //конструктор по умолчанию
{
	arr = NULL;
	size = 0;
	sign = '+';
}

Decimal::Decimal(const long long num)
{
	size = 0;
	long long x = num;
	sign = '+';
	if (num < 0)
	{
		sign = '-';
		x = -num;
	}
	while (x > 0)
	{
		size++;
		x /= 10;
	}
	arr = new unsigned char[size];
	x = abs(num);
	for (int i = 0; i < size; i++)
	{
		arr[i] = x % 10;
		x /= 10;
	}
}

Decimal::Decimal(const Decimal& num) //копирование
{
	*this = num;
}

Decimal::~Decimal()
{
	if (arr != NULL)
		delete[] arr;
	size = 0;
	sign = 0;
}

Decimal& Decimal::operator= (const Decimal& num)
{
	if (arr != NULL && size > 0)
		delete[] arr;
	size = num.size;
	arr = new unsigned char[size];
	for (int i = 0; i < size; i++)
		arr[i] = num.arr[i];
	sign = num.sign;
	return *this;
}

Decimal Decimal::operator+ (const Decimal& num)
{
	if (sign == num.sign)
		return this->add(num);
	if (sign == '+')
		return this->sub(num);
	Decimal tmp = num;
	return tmp.sub(*this);
}

Decimal Decimal::operator-(const Decimal& num)
{
	if (sign == num.sign)
		if (sign == '+')
			return this->sub(num);
		else
		{
			Decimal tmp = num;
			return tmp.sub(*this);
		}
	if (num.sign == '-')
	{
		Decimal tmp = num;
		tmp.sign = '+';
		return this->add(tmp);
	}
	Decimal tmp = *this;
	return tmp.add(num);
}

bool Decimal::operator==(const Decimal& num)
{
	if (size != num.size || sign != num.sign)
		return false;
	for (int i = 0; i < size; i++)
		if (arr[i] != num.arr[i])
			return false;
	return true;
}

bool Decimal::operator!=(const Decimal& num)
{
	return !(*this == num);
}

bool Decimal::operator>(const Decimal& num)
{
	if (sign != num.sign)
		if (sign == '+') return true;
		else return false;
	else
		if ((sign == '-' && size > num.size) || (sign == '+' && size < num.size)) return false;
		else if ((sign == '-' && size < num.size) || (sign == '+' && size > num.size)) return true;
	int x = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == num.arr[i]) x++;
		if (sign == '+')
		{
			if (arr[i] < num.arr[i]) return false;
		}
		else
			if (arr[i] > num.arr[i]) return false;
	}
	if (x == size)
		return false;
	return true;
}

bool Decimal::operator>=(const Decimal& num)
{
	return *this == num || *this > num;
}

bool Decimal::operator<(const Decimal& num)
{
	Decimal tmp = num;
	return tmp > (*this);
}

bool Decimal::operator<=(const Decimal& num)
{
	return *this == num || *this < num;
}

Decimal abs(const Decimal& num)
{
	Decimal tmp = num;
	tmp.sign = '+';
	return tmp;
}

istream& operator>>(istream& stream, Decimal& num)
{
	string strNum;
	stream >> strNum;
	num.sign = '+';
	int n = strNum.length();
	num.size = n;
	if (strNum[0] == '-')
	{
		num.size--;
		num.sign = '-';
	}
	num.arr = new unsigned char[num.size];
	for (int i = 0; i < n; i++)
		num.arr[i] = strNum[n - 1 - i] - '0';

	return stream;
}

ostream& operator<<(ostream& stream, const Decimal& num)
{
	if (num.sign == '-')
		stream << '-';
	for (int i = num.size - 1; i >= 0; i--)
		stream << (int)num.arr[i];
	return stream;
}
