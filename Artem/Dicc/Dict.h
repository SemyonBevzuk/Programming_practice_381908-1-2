#pragma once
#ifndef INCLUDE_CLASS_DICTIONARY_HPP_
#define INCLUDE_CLASS_DICTIONARY_HPP_
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <locale.h>
#include <Windows.h>

using namespace std;

class Word {
private:
	string eng_word;
	string rus_word;

public:
	Word();
	Word(string word, string translation);

	const string get_eng_word() { return eng_word; }
	const string get_rus_word() { return rus_word; }

	void set_eng_word(string word);
	void set_rus_word(string word);

	void show_word();
	friend bool operator==(const Word& left, const Word& right);
};

class Dictionary {
public:
	Word* arr;
	int size;

	Dictionary();
	Dictionary(const Word word);

	void AddWord(string word, string translation);
	void ChangeTranslation(int index, string translation);
	void ShowTranslation(int index);
	int index_of_word(string word);
	void number_of_words();
	void Read(string filename);
	void Load(string filename);
	Word& operator[](const int index);
	Dictionary& operator=(Dictionary& arr_);
	Dictionary operator+(Dictionary& arr_);
};

#endif INCLUDE_CLASS_DICTIONARY_HPP_