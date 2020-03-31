#include "dictionary.h"

Dictionary::Dictionary()
{
}

string Dictionary::print_translation(string name) //Вывод
{
	it = dict.find(name);

	if (it == dict.end())
	{
		return "Такого слова нет в словаре";
	}
	else
	{
		return it->second;
	}
}

void Dictionary::insert(string eng, string rus) //Добавление слов в словарь
{
	dict.insert(make_pair(eng, rus));
}

void Dictionary::change(string eng, string rus) //Изменение перевода
{
	it = dict.find(eng);
	if (it == dict.end())
	{
		insert(eng, rus); //Добавление в словарь
	}
	else
	{ 
		//обновление 
		dict.erase(eng); 
		insert(eng, rus);
	}

}

bool Dictionary::IsExist(string name) //Наличие слова в словаре
{
	it = dict.find(name);
	if (it == dict.end())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Dictionary::GetSize() //Размер словаря
{
	return dict.size();
}

void Dictionary::file_write() //Запись в файл
{
	ofstream fout; //поток
	fout.open("dictOut.txt"); // окрываем файл для записи

	for (it = dict.begin(); it != dict.end(); it++)
	{
		fout << it->first << " " << it->second << endl;
	}

	fout.close();
}
void Dictionary::file_read()  //Чтение из файла
{
	string eng;
	string rus;

	ifstream fout("dictIn.txt"); // окрываем файл для чтения
	while (!fout.eof())
	{
		fout >> eng >> rus;
		dict[eng] = rus;
	}
	fout.close();
}

const Dictionary Dictionary::operator+(const Dictionary& d)
{
	string eng;
	string rus;

	Dictionary result = d;
	it = dict.begin();
	for (it; it != dict.end(); it++)
	{
		eng = it->first;
		rus = it->second;
		result.insert(eng, rus);
	}
	return result;

}

Dictionary& Dictionary::operator=(const Dictionary& d) //Присваивание
{
	dict = d.dict;
	return *this;
}
