#include "Kassa.h"
#include <iostream>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	string str;
	cout << "Имя файла с данными склада: "; cin >> str;
	ifstream is;
	is.open(str);
	Sklad sklad;
	is >> sklad;
	is.close();
	Kassa kassa;
	char c;
	int i;
	while (true)
	{
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "1 - «сканировать» очередной товар" << endl;
		cout << "2 - получить описание товара со склада" << endl;
		cout << "3 - добавить данные о товаре в чек" << endl;
		cout << "4 - сформировать чек за покупку" << endl;
		cout << "5 - рассчитать итоговую сумму к оплате" << endl;
		cout << "6 - удалить выбранный товар из покупки" << endl;
		cout << "--------------------------------------" << endl;
		cin >> c;
		system("cls");
		switch (c)
		{
		case '1':
			cout << "Код товара: "; cin >> i;
			kassa.Scan(i);
			break;
		case '2':
			cout << kassa.GetDescription(sklad);
			break;
		case '3':
			cout << "Количество: "; cin >> i;
			kassa.AddToCheck(kassa.GetDescription(sklad), i);
			break;
		case '4':
			cout << "Имя файла для записи: "; cin >> str;
			kassa.GenerateCheck(str);
			break;
		case '5':
			cout << kassa.GetResult() << " рублей" << endl;
			break;
		case '6':
			cout << "Название: "; cin >> str;
			cout << "Количество: "; cin >> i;
			kassa.Delete(str, i);
			break;
		default:
			return;
		}
		system("pause");
	}
}