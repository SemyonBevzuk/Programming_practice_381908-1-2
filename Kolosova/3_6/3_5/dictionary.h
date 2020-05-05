#pragma once
/*Разработать класс Dictionary.

Класс должен предоставлять возможность формировать англо - русский словарь.

В минимальном варианте каждому английскому слову соответствует ровно одно русское слово - перевод.

Класс должен содержать необходимые служебные методы(конструкторы, деструктор и пр.).

Класс должен предоставлять следующие операции :

добавить в словарь слово и его перевод
изменить перевод указанного слова,
узнать перевод выбранного слова,
проверить наличие слова в словаре,
узнать число слов в словаре,
сохранить словарь в файл, считать словарь из файла.
перегрузить операции присваивания и объединения словарей.*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "pss.h"
using namespace std;

class Dict {
private:
	vector<pss> dict;
	int seekpos(string word);
public:
	Dict();
	Dict(const string filename);
	Dict(const Dict& d);
	~Dict();
	void load(const string filename);
	void save(const string filename);
	string translate(const string word);
	pair<int, int> seek(const string word);
	int count();
	int add(const string word, const string translation);
	int changetrans(const string word, const string translation);
	void print();
	Dict& operator=(const Dict& d);
	Dict operator+(const Dict& d);
	Dict& operator+=(const Dict& d);
	Dict& sort_();
};