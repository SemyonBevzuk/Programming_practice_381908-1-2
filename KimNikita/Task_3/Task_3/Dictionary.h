#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

using namespace std;

class Dictionary {
private:
	vector<pair<string, string>> slov;
	void check(string&, char);
public:
	Dictionary() {}
	Dictionary(const Dictionary&);
	Dictionary(vector<pair<string, string>>);
	~Dictionary() {};
	Dictionary& operator=(const Dictionary&);
	Dictionary& operator+=(const Dictionary&);
	const Dictionary operator+(const Dictionary&)const;
	void add(string, string);
	void change_translate(string, string);
	const string get_translate(string);
	bool find(string);
	const int size()const;
	friend ifstream& operator>>(ifstream&, Dictionary&);
	friend ofstream& operator<<(ofstream&, const Dictionary&);
};