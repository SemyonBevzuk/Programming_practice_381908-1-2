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
	Dictionary(const Dictionary& d);

	void insert(string eng, string rus); //Добавление слов в словарь
	void change(string end); //Изменение перевода
	void print_translation(string name); //Вывод
	void existence(string name); //Наличие слова в словаре
	int count(); //Размер словаря
	void file_write(); //Запись в файл
	void file_read(); //Чтение из файла
	void file_read(string file_name1, string file_name2); //Чтение из двух файлов
	Dictionary& operator=(const Dictionary& d); //Присваивание
};