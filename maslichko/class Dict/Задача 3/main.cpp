#include <iostream>
#include <fstream>
#include "dictionary.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251); //Установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //В поток вывода

	int menu;
	string test1, test2, test3, test4;
	Dictionary d1, d2, d3;

	while (1)
	{
		cout << endl;
		cout << "1. Добавить в словарь слово и его перевод" << endl;
		cout << "2. Изменить перевод слова" << endl;
		cout << "3. Узнать перевод слова" << endl;
		cout << "4. Проверить наличие слова в словаре" << endl;
		cout << "5. Узнать число слов в словаре" << endl;
		cout << "6. Сохранить словарь в файл" << endl;
		cout << "7. Считать словарь из файла" << endl;
		cout << "8. Объединить словари" << endl;
		cout << "9. Присваивание" << endl;
		cout << endl << "Выберите нужное действие: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "Введите пару слов" << endl;
			cin >> test1 >> test2;
			d1.insert(test1, test2);
			break;
		case 2:
			cout << "Слово, у которого нужно изменить перевод и новый перевод: ";
			cin >> test3 >> test4;
			d1.change(test3, test4);
			break;
		case 3:
			cout << "Введите слово, у которого нужно узнать перевод: ";
			cin >> test3;
			cout << d1.translate(test3);
			break;
		case 4:
			cout << "Введите слово, которое нужно найти: ";
			cin >> test3;
			cout << d1.IsExist(test3);
			break;
		case 5:
			cout << "Количество слов в словаре: " << d1.GetSize() << endl;
			break;
		case 6:
			d1.file_write();
			break;
		case 7:
			d2.file_read();
			break;
		case 8:
			d3 = d1 + d2;
			break;
		case 9:
			d2 = d1;
			break;
		}
	}

	system("pause");
}
