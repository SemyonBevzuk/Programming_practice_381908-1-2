#pragma once

struct Purchase
{
	string title;
	int price;
	int count;
	int result;
	int disc_per;

	friend ofstream& operator<<(ofstream& out, const Purchase& P);
};

inline ofstream& operator<<(ofstream& out, const Purchase& P)
{
	out << P.title << endl;
	out << P.price << endl;
	out << P.count << endl;
	out << P.result << endl;
	return out;
}