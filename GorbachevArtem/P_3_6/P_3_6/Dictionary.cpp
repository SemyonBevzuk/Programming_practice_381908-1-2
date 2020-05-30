#include "Dictionary.h"

int Dictionary::IndexOfWord(const vector<string>& vec, const string word) const
{
	const_cast<vector<string>&>(vec).push_back(word);
	int i = 0;
	while (vec[i] != word) i++;
	const_cast<vector<string>&>(vec).pop_back();
	if (i != en.size()) return i;
	return -1;
}

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(int n, const string _en[], const string _ru[])
{
	try {
		if (n < 1)
			throw "Ошибка - длина массивов должна быть положительной!";
		en.resize(n);
		ru.resize(n);
		for (int i = 0; i < n; i++) {
			en[i] = _en[i];
			ru[i] = _ru[i];
		}
	}
	catch (const char* str) {
		cout << str << endl;
	}
}

Dictionary::Dictionary(const vector<string>& _en, const vector<string>& _ru)
{
	en = _en;
	ru = _ru;
	int eSize = en.size(), rSize = ru.size();
	try {
		if (eSize != rSize)
			throw "Ошибка - массивы должны быть одинаковой длины!";
	}
	catch (const char* str) {
		cout << str << endl;
		int n = eSize < rSize ? eSize : rSize;
		en.resize(n);
		ru.resize(n);
	}
}

Dictionary::Dictionary(const Dictionary & D)
{
	en = D.en;
	ru = D.ru;
}

Dictionary::~Dictionary()
{
}

void Dictionary::AddWord(const string eWord, const string rWord)
{
	int i = IndexOfWord(en, eWord);
	if (i != -1 && ru[i] == rWord) return;
	en.push_back(eWord);
	ru.push_back(rWord);
}

void Dictionary::ChangeTranslation(const string word, const string translation)
{
	int i = IndexOfWord(en, word);
	if (i != -1) 
		ru[i] = translation;
	else {
		i = IndexOfWord(ru, word);
		if (i != -1)
			en[i] = translation;
	}
}

string Dictionary::Translate(const string word) const
{
	int i = IndexOfWord(en, word);
	if (i != -1) return ru[i];
	i = IndexOfWord(ru, word);
	if (i != -1) return en[i];
	return string();
}

bool Dictionary::IsContain(const string word) const
{
	if (IndexOfWord(en, word) != -1 || IndexOfWord(ru, word) != -1) return true;
	return false;
}

int Dictionary::Size() const
{
	return en.size();
}

Dictionary & Dictionary::operator=(const Dictionary & D)
{
	en = D.en;
	ru = D.ru;
	return *this;
}

Dictionary Dictionary::operator+(const Dictionary & D) const
{
	Dictionary res(*this);
	int size = D.Size();
	for (int i = 0; i < size; i++)
		if (!res.IsContain(D.en[i]) || !res.IsContain(D.ru[i])) {
			res.en.push_back(D.en[i]);
			res.ru.push_back(D.ru[i]);
		}
	return res;
}

Dictionary & Dictionary::operator+=(const Dictionary & D)
{
	*this = *this + D;
	return *this;
}

ofstream & operator<<(ofstream & out, const Dictionary & D)
{
	int size = D.Size();
	out << size << endl;
	for (int i = 0; i < size; i++) {
		out << D.en[i] << endl;
		out << D.ru[i] << endl;
	}
	return out;
}

ifstream & operator>>(ifstream & in, Dictionary & D)
{
	int size;
	in >> size;
	D.en.resize(size);
	D.ru.resize(size);
	for (int i = 0; i < size; i++) {
		in >> D.en[i];
		in >> D.ru[i];
	}
	return in;
}