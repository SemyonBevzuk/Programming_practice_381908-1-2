#pragma once
/*Создать класс Hex для работы с беззнаковыми целыми шестнадцатеричными числами, используя для представления числа массив из элементов типа 
unsigned char, каждый из которых является шестнадцатеричной цифрой.

Младшая цифра имеет меньший индекс.

Размер массива задается как аргумент конструктора. Реализовать операции:

присваивания
арифметические: +, -
сравнения
операцию индексации с контролем выхода индекса за границы массива.
операции << и >> для сохранения себя в файле и чтения из файла*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

class Hex {
private:
	vector<bitset<5>> d;
public:
	Hex();
	Hex(const Hex& h);
	Hex(string s);
	~Hex();
	vector<bitset<5>>& get_d();
	int get_size();
	string toString() const;
	friend Hex stoh(string s);
	Hex& operator=(const Hex& h);
	Hex& operator=(const string& h);
	Hex operator+(const Hex& h);
	Hex operator-(const Hex& h);
	bool operator<(const Hex& a) const;
	bool operator>(const Hex& a) const;
	bool operator<=(const Hex& a);
	bool operator>=(const Hex& a);
	bool operator==(const Hex& a);
	bool operator!=(const Hex& a);
	Hex& operator+=(const Hex& h);
	Hex& operator-=(const Hex& h);
	bitset<5> & operator[](const int index);
	

	friend istream& operator>>(istream& in, Hex& a);
	friend ostream& operator<<(ostream& out, const Hex& a);
	friend ifstream& operator>>(ifstream& in, Hex& a);
	//friend ofstream& operator<<(ofstream& out, const Hex& a);
	
};
