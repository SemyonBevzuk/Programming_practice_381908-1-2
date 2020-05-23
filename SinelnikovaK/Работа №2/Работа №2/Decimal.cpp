#include "Decimal.h"

size_t max(const size_t num1, const size_t num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

size_t min(const size_t num1, const size_t num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

Decimal max(Decimal num1, Decimal num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

Decimal min(Decimal num1, Decimal num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

Decimal Decimal::add(const Decimal& num)
{
	Decimal Result;
	Result.size = __max(size, num.size);
	Result.sign = sign;
	Result.arr = new unsigned char[Result.size + 1];

	for (size_t i = 0; i < size; i++)
		Result.arr[i] = arr[i];

	for (size_t i = size; i < Result.size + 1; i++)
		Result.arr[i] = 0;

	for (size_t i = 0; i < num.size; i++)
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
	Decimal _num = num;
	Decimal Result = max(this->abs(), _num.abs());
	if (Result == this->abs())
		Result.sign = '+';
	else
		Result.sign = '-';
	Decimal tmp = min(this->abs(), _num.abs());
	int f = 0;
	for (size_t i = 0; i < tmp.size; i++)
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
	while (Result.arr[Result.size - 1] == 0 && Result.size > 1)
		Result.size--;
	return Result;
}

Decimal::Decimal() //конструктор по умолчанию
{
	arr = nullptr;
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
	x = std::abs(num);
	for (size_t i = 0; i < size; i++)
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
	if (arr != nullptr)
		delete[] arr;
	size = 0;
	sign = 0;
}

Decimal& Decimal::operator= (const Decimal& num)
{
	if (*this == num)
		return *this;
	if (arr != nullptr && (sign == '-' || sign == '+'))
		delete[] arr;
	size = num.size;
	arr = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
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
	for (size_t i = 0; i < size; i++)
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
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (arr[i] == num.arr[i]) x++;
		if (sign == '+')
		{
			if (arr[i] < num.arr[i]) return false;
		}
		else
			if (arr[i] > num.arr[i]) return false;
		if (i == 0)
			break;
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

Decimal Decimal::abs()
{
	sign = '+';
	return *this;
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
	for (size_t i = 0; i < (size_t)n; i++)
		num.arr[i] = strNum[n - 1 - i] - '0';

	return stream;
}

ostream& operator<<(ostream& stream, const Decimal& num)
{
	if (num.sign == '-')
		stream << '-';
	for (size_t i = num.size - 1; i > 0; i--)
		stream << (int)num.arr[i];
	stream << (int)num.arr[0];
	return stream;
}
