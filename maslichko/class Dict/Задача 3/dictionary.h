#include<iostream>
#include<fstream>
#include <map>

using namespace std;

class Dictionary
{
private:
	map <string, string> dict;
	map <string, string> ::iterator it;
public:
	Dictionary();

	//Dictionary(const Dictionary& d);

	void insert(string eng, string rus); //Добавление слов в словарь
	void change(string end, string rus); //Изменение перевода
	string print_translation(string name); //Вывод
	bool IsExist(string name); //Наличие слова в словаре
	int GetSize(); //Размер словаря
	void file_write(); //Запись в файл
	void file_read(); //Чтение из файла
	const Dictionary operator+(const Dictionary& d); //Объединение словарей
	Dictionary& operator=(const Dictionary& d); //Присваивание
};