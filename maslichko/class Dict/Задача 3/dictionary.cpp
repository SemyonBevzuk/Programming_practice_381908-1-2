#include "dictionary.h"

Dictionary::Dictionary()
{
}

void Dictionary::print_translation(string name) //Вывод
{
	it = dict.find(name);

	if (it == dict.end())
	{
		cout << "Слова " << name << " нет в словаре" << endl;
	}
	else
	{
		cout << "Перевод: " << it->second << endl;
	}
}

void Dictionary::insert(string eng, string rus) //Добавление слов в словарь
{
	dict.insert(make_pair(eng, rus));
}

void Dictionary::change(string eng) //Изменение перевода
{
	string temp;
	it = dict.find(eng);
	if (it == dict.end())
	{
		cout << "Слова " << eng << " нет в словаре" << endl;
	}
	else
	{
		dict.erase(eng);
		cout << "Введите новый перевод: ";
		cin >> temp;
		insert(eng, temp);
	}

}

void Dictionary::existence(string name) //Наличие слова в словаре
{
	it = dict.find(name);
	if (it == dict.end())
	{
		cout << "Слова " << name << " нет в словаре" << endl;
	}
	else
	{
		cout << "Слово " << name << " в словаре есть. Перевод: " << it->second << endl;
	}
}

int Dictionary::count() //Размер словаря
{
	return dict.size();
}

void Dictionary::file_write() //Запись в файл
{
	ofstream out; //поток
	out.open("dictOut.txt"); // окрываем файл для записи

	for (it = dict.begin(); it != dict.end(); it++)
	{
		out << it->first << " " << it->second << endl;
	}

	out.close();
}
void Dictionary::file_read()  //Чтение из файла
{
	string eng;
	string rus;

	ifstream in("dictIn.txt"); // окрываем файл для чтения
	while (!in.eof())
	{
		in >> eng >> rus;
		dict[eng] = rus;
	}
	in.close();
}

void Dictionary::file_read(string name1, string name2) //Чтение из двух файлов
{
	string eng;
	string rus;
	
	ifstream in1(name1); // окрываем файл для чтения
	ifstream in2(name2); // окрываем файл для чтения
	while (!in1.eof())
	{
		in1 >> eng >> rus;
		dict[eng] = rus;
	}
	while (!in2.eof())
	{
		in2 >> eng >> rus;
		dict[eng] = rus;
	}
	in1.close();
	in2.close();
}

Dictionary& Dictionary::operator=(const Dictionary& d) //Присваивание
{
	dict = d.dict;
	return *this;
}
