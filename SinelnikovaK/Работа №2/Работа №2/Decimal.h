#pragma once
#include <iostream>
using namespace std;

class Decimal
{
private:
	unsigned char* arr; // динам.массив с целочисленными переменными (указатель)
	size_t size; // размер массива
	char sign; // знак числа

	Decimal add(const Decimal& num);
	Decimal sub(const Decimal& num);
	Decimal abs();
public:
	Decimal();
	Decimal(const long long num);
	Decimal(const Decimal& num);
	~Decimal();

	Decimal& operator= (const Decimal& num);
	Decimal operator+ (const Decimal& num);
	Decimal operator- (const Decimal& num);

	bool operator== (const Decimal& num);
	bool operator!= (const Decimal& num);
	bool operator>  (const Decimal& num);
	bool operator>= (const Decimal& num);
	bool operator<  (const Decimal& num);
	bool operator<= (const Decimal& num);

	friend istream& operator>> (istream& stream, Decimal& num);
	friend ostream& operator<< (ostream& stream, const Decimal& num);
};
