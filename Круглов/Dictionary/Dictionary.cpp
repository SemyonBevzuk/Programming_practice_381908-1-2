#include"Dictionary.h"
#include <fstream>
#include<iostream>
#include<algorithm>

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(const Dictionary& d)
{
	Dict = d.Dict;
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
	return Dict.begin();
}

map <string, string> ::iterator Dictionary::end()
{
	return Dict.end();
}

int Dictionary::getSize()
{
	return Dict.size();
}

string Dictionary::translateToRussian(string eng)
{
	it = Dict.find(eng);
	if (it != Dict.end())
		return Dict[eng];
	else
		throw eng;
}

string Dictionary::translateToEnglish(string rus)
{
	it = Dict.begin();
	while (it != Dict.end()) 
	{
		if (it->second == rus)
		{
			return it->first;
		}
		it++;
	}
	throw rus;
}

void Dictionary::changeTranslation(string eng, string rus)
{
	it = Dict.find(eng);
	if (it != Dict.end())
		Dict[eng] = rus;
}

bool Dictionary::presence(string eng)
{
	it = Dict.find(eng);
	if (it == Dict.end())
		return false;
	return true;
}

void Dictionary::save()
{
	ofstream fout( "Dictionary.txt");
	for (it=Dict.begin(); it != Dict.end(); it++)
	{
		fout << (*it).first << " " << it->second << "\n";
	}
	fout.close();
}

void Dictionary::read()
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

Dictionary& Dictionary::operator=(const Dictionary& d)
{
	if (this == &d) return *this;
	Dict = d.Dict;
	return *this;
}

const Dictionary Dictionary:: operator+(const Dictionary& d)
{
	string eng, rus;
	Dictionary res = d;
	it = Dict.begin();
	for (it; it != Dict.end(); it++)	
	{
		eng = it->first;
		rus = it->second;
		res.insert(eng, rus);
	}
	return res;
}