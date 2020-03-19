#include"Dictionary.h"
#include <fstream>
#include<iostream>

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(Dictionary& d)
{
	string eng, rus;
	it = d.begin();
	for (it; it != d.end(); it++)
	{
		eng = it->first;
		rus = it->second;
		Dict[eng] = rus;
	}
}

void Dictionary::insert(string eng, string rus)
{
	Dict[eng] = rus;
}
 
void Dictionary::insert(pair<string, string> p)
{
	Dict[p.first] = p.second;
}

map <string, string> ::iterator Dictionary::begin()
{
	{
		return Dict.begin();
	}
}

map <string, string> ::iterator Dictionary::end()
{
	return Dict.end();
}

int Dictionary::size()
{
	return Dict.size();
}

string Dictionary::Translate(string eng)
{
	it = Dict.find(eng);
	if (it != Dict.end())
		return Dict[eng];
	else
		return "Такого слова нет";
}

void Dictionary::ChangeTranslation(string eng, string rus)
{
	it = Dict.find(eng);
	if (it != Dict.end())
		Dict[eng] = rus;
	else
		cout << "Такого слова нет";
}

bool Dictionary::Presence(string eng)
{
	it = Dict.find(eng);
	if (it == Dict.end())
		return 0;
	return 1;
}

void Dictionary::Save()
{
	ofstream fout( "Dictionary.txt");
	for (it=Dict.begin(); it != Dict.end(); it++)
	{
		fout << (*it).first << " " << it->second << "\n";
	}
	fout.close();
}

void Dictionary::Read()
{
	ifstream fout("Dictionary.txt");
	string eng, rus;
	while (!fout.eof())
	{
		fout >> eng >> rus;
		Dict[eng] = rus;
	}
	fout.close();
}

Dictionary& Dictionary::operator=(Dictionary& d)
{
	string eng, rus;
	it = d.begin();
	Dict.clear();
	for (it; it != d.end(); it++)
	{
		eng = it->first;
		rus = it->second;
		Dict[eng] = rus;
	}
	return *this;
}

Dictionary Dictionary:: operator+(Dictionary& d)
{
	string eng, rus;
	Dictionary res(d);
	it = d.begin();
	for (it; it != d.end(); it++)
	{
		eng = it->first;
		rus = it->second;
		res.insert(eng, rus);
	}
	return *this;
}