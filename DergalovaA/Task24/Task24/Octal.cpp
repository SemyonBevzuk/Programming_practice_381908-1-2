#include "Octal.h"
#include <cmath>

void Octal::addR()
{ //i is the highest razryad
	size++;
	unsigned char* n2 = new unsigned char[size];
	//sdvig
	for (size_t j = 0; j > size-1; j++)
		n2[j + 1] = n[j];
	//n2[0] is empty, cause there is new razryad
	delete[] n;
	n = new unsigned char[size];
	for (size_t i = 1; i < size; i++)
		n[i] = n2[i];
	delete[] n2;
	n[0] = 1; //new razryad
}

void Octal::cutR()
{ //the highest razryad is equal to 0
	size--;
	unsigned char* n2 = new unsigned char[size];
	//sdvig
	for (size_t j = 0; j > size-1; j++)
		n2[j] = n[j + 1];
	delete[] n;
	n = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
		n[i] = n2[i];
	delete[] n2;

	
}

Octal::Octal()
{
	size = 0;
	n = nullptr;
}

Octal::Octal(int in)
{
	int i = 0;
	int in2 = in;
	while (in2 > 0)
	{
		i++;
		in2 /= 10;
		//length
	}
	size = i;
	n = new unsigned char[size];
	i--;
	for (; i >= 0; i--)
	{
		int a = in % 10;
		n[i] = a;
		in /= 10;
	}
}

Octal::Octal(const Octal& in)
{
	size = in.size;
	n = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
	{
		n[i] = in.n[i];
	}

}

Octal::~Octal()
{
	if (n)
		delete[] n;
}

Octal Octal::operator+(const Octal& b)
{
	Octal res, a = *this, c = b;
	int i;
	if (a.size < c.size)
	{
		i = res.size = c.size;
		Octal tmp = a;
		a = c;
		c = tmp;
	}
	else
		i = res.size = a.size;
	int d = a.size - c.size;
	res.n = new unsigned char[i];
	i--;
	for (; i >= 0; i--)
	{
		int k;
		if (i < d)
			k = a.n[i];
		else
			k = a.n[i] + c.n[i - d];

		if (k > 7 && k < 15)
		{
			k -= 8;
			if (i == 0) //higher razryad
				res.addR();
			else
			{
				res.n[i - 1] ++;
				if (res.n[i - 1] >= 8)
					res.addR();
			}
		}

		res.n[i] = k;
	}
	return res;
}

Octal Octal::operator-(const Octal& b)
{
	Octal res, a = *this, c = b;
	int i;
	if (a.size < c.size)
		i = res.size = c.size;
	else
		i = res.size = a.size;
	int d = a.size - c.size;
	res.n = new unsigned char[i];
	i--;
	for (; i >= 0; i--)
	{
		int k;
		if (i < d)
			k = a.n[i];
		else
			k = a.n[i] - c.n[i - d];

		if (k < 0)
		{
			if (a.n[i - 1] == 1) //res < 10
			{
				res.cutR();
				i--;
			}
			else
			{
				a.n[i - 1] --;
				if (a.n[i - 1] < 1)
					a.cutR();
			}
			k += 8;
		}
		res.n[i] = k;
	}
	if (res.n[0] == 0)
		res.cutR();
	return res;
}

Octal &Octal::operator=(const Octal& a)
{
	if (*this == a)
			return *this; //if this == a, there is no smysl to work
	delete[] n;
	size = a.size;
	n = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
		n[i] = a.n[i];
	return *this;
}

Octal &Octal::operator=(int a)
{
	int i = 0;
	int a2 = a;
	while (a2 > 0)
	{
		i++;
		a2 /= 10;
		//length
	}
	size = i;
	n = new unsigned char[i];
	i--;
	for (; i >= 0; i--)
	{
		n[i] = a % 10;
		a /= 10;
	}
	return *this;
}

bool Octal::operator==(const Octal& a)
{
	bool f = false;
	if (size == a.size)
	{
		int i = size;
		while (n[i] == a.n[i] && i > 0)
		{
			i--;
		}
		if (i == 0) f = true;
	}
	return (f);
}

bool Octal::operator!=(const Octal& a)
{
	return(!(*this == a));
}

bool Octal::operator>(const Octal & a)
{
	bool f = false;
	if (size > a.size)
		f = true;
	else
		if (size == a.size)
		{
			int i = size;
			while (n[i] > a.n[i] && i > 0)
			{
				i--;
			}
			if (i == 0) f = true;
		}
	return (f);
}

bool Octal::operator<(const Octal & a)
{
	bool f = false;
	if (size < a.size)
		f = true;
	else
		if (size == a.size)
		{
			int i = size;
			while (n[i] < a.n[i] && i > 0)
			{
				i--;
			}
			if (i != 0) f = true;
		}
	return (f);
}

istream & operator>>(istream & in, Octal & a)
{
	int s;
	in >> s;
	delete[] a.n;
	a.size = s;
	a.n = new unsigned char[a.size];
	for (int i = 0; i < s; i++)
	{
		unsigned char k;
		in >> k;
		a.n[i] = k - '0';
	}
	return in;
}

ostream & operator<<(ostream & out, const Octal & a)
{
	out << "[" << a.size << "] ";
	for (size_t i = 0; i < a.size; i++) {
		out << (int)a.n[i];
	}
	out << endl;
	return out;
}