#include"Dictionary.h"
#include <iostream>
#include<locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Dictionary d1, d2;
	map<string, string> ::iterator it;
	d1.insert("translate", "перевести");
	d2.insert("COVID-19", "коронавирус");
	Dictionary d3(d2);
	for (it = d3.begin(); it != d3.end(); it++)
	{
		cout << it->first << " " << it->second << "\n";
	}
	//d3 = d1 + d2;
	cout << d1.size() << "- Размер \n";
	cout << d1.Presence("good") << "- есть ли слово" << "\n";
	cout << d1.Translate("translate");
}

