#pragma once
#include <stdio.h>
#include <string>
#include <string>
#include <cstring>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <algorithm>

using namespace std;
class Dictionary
{
private:
	vector<pair<wstring, wstring>>dictionary;
public:

	//Constructors and destructor
	Dictionary();//Default
	Dictionary(int size);//Initializer
	Dictionary(const Dictionary& other);//Copy
	~Dictionary();//Destructor

	//Secondary functions
	void Resize(int size);
	bool AddWord(wstring eng, wstring rus);
	bool ChangeTranslation(wstring word, wstring translation);
	int FindTranslation(wstring word);
	void PrintStroka(int stroka);
	bool FindWord(wstring word);
	int Size();
	void Clear();

	//Operator overload
	Dictionary& operator=(const Dictionary& other);//Assignment operator overload
	Dictionary operator+=(const Dictionary& other);//Addition operator overload
	friend wistream& operator>> (wistream& wistream, Dictionary& c);//Overload operator output from the stream
	friend wostream& operator<< (wostream& stream, const Dictionary& c);//Overload operator input into the stream

	//Methods
	void ChangeRegistr();
	void SortAlphabet();

};