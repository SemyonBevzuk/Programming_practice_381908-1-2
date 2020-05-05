#pragma once
#include <vector>
#include <string>
using namespace std;
class pss {
	string s[2];
public:
	pss();
	pss(string str1, string str2);
	pss& operator=(const pss& p);
	pss& operator=(std::initializer_list<string> str);
	string& operator[](const int index);
	~pss();
};
