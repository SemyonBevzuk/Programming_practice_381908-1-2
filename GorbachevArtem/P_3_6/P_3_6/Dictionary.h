#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Dictionary
{
private:
	vector<string> en;
	vector<string> ru;
	int IndexOfWord(const vector<string>& vec, const string word) const;
public:
	Dictionary();
	Dictionary(int n, const string _en[], const string _ru[]);
	Dictionary(const vector<string>& _en, const vector<string>& _ru);
	Dictionary(const Dictionary& D);
	~Dictionary();
	void AddWord(const string eWord, const string rWord);
	void ChangeTranslation(const string word, const string translation);
	string Translate(const string word) const;
	bool IsContain(const string word) const;
	int Size() const;
	friend ofstream& operator<<(ofstream& out, const Dictionary& D);
	friend ifstream& operator>>(ifstream& in, Dictionary& D);
	Dictionary& operator=(const Dictionary& D);
	Dictionary operator+(const Dictionary& D) const;
	Dictionary& operator+=(const Dictionary& D);
};