#pragma once
#include <fstream>
#include <string>
using namespace std;

struct Product
{
	int code;
	string title;
	int price;
	int disc_per;

	friend ostream& operator<<(ostream& out, const Product& P);
	friend ifstream& operator>>(ifstream& in, Product& P);
};

inline ifstream& operator>>(ifstream& in, Product& P)
{
	in >> P.code >> P.title >> P.price >> P.disc_per;
	return in;
}

inline ostream& operator<<(ostream& out, const Product& P)
{
	out << P.code << endl;
	out << P.title << endl;
	out << P.price << endl;
	out << P.disc_per << endl;
	return out;
}