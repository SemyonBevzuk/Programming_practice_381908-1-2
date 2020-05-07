#pragma once
#include <iostream>
using namespace std;

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

class Decimal
{
private:
	unsigned char* arr; // динам.массив с целочисленными переменными (указатель)
	int size; // размер массива
	char sign; // знак числа

	Decimal add(const Decimal& num);
	Decimal sub(const Decimal& num);
	friend Decimal abs(const Decimal& num);
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

