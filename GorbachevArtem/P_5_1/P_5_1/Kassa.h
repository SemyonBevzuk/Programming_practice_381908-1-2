#pragma once
#include "Sklad.h"
#include "Purchase.h"

class Kassa
{
private:
	vector<Purchase> vec;
	int code;
	int cost;
	int discount;
	int result;
public:
	Kassa() { code = cost = discount = result = 0; };
	~Kassa() {};
	void Scan(int _code) { code = _code; };
	Product GetDescription(const Sklad& sklad) { return sklad[code]; };
	void AddToCheck(const Product& P, int count);
	void Delete(string title, int count);
	int GetResult() { return result; };
	void GenerateCheck(string file) const;
};

