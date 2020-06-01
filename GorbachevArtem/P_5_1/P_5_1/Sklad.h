#pragma once
#include "Product.h"
#include <vector>

class Sklad
{
private:
	vector<Product> vec;
public:
	Sklad() {};
	~Sklad() {};
	Product operator[](int code) const;
	friend ifstream& operator>>(ifstream& in, Sklad& S);
};

inline Product Sklad::operator[](int code) const
{
	Product P;
	P.code = code;
	int i = 0;
	const_cast<vector<Product>&>(vec).push_back(P);
	while (vec[i].code != code) i++;
	const_cast<vector<Product>&>(vec).pop_back();
	if (i < vec.size()) return vec[i];
	return P;
}

inline ifstream& operator>>(ifstream& in, Sklad& S)
{
	int n;
	in >> n;
	S.vec.resize(n);
	for (int i = 0; i < n; i++)
		in >> S.vec[i];
	return in;
}