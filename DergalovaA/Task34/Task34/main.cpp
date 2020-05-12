#include <iostream>
#include "menu.h"
#include <clocale>
#include <conio.h>

int main()
{
	bool choose;
	cout << "Would you like to create a menu (0) or use it from file (1)? Enter the corresponding number:" << endl;
	cin >> choose;
	if (choose)
	{
		try
		{
			Menu m("Menu.txt");
			m.Display();
			int k = m.SelectionMenu();
			m.Clear();
			cout << k;
			_getch();
		}
		catch (ExMenu exp)
		{
			switch (exp.type)
			{
			case(Size):
				cout << "Error on size = " << exp.intSize << endl;
				break;
			case(outofAr):
				cout << "Size Array != Num String: Size Array = " << exp.intSize << endl;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		try {
			cout << "Enter the menu coordinates as x y: ";
			int x, y;
			cin >> x >> y;
			cout << "Enter the size of the menu bar: ";
			int size;
			cin >> size;
			cout << "Enter the number of menu items: ";
			int num;
			cin >> num;
			cout << "Enter the names of the menu items: " << endl;
			string* mn = new string[num];

			for (int i = 0; i < num; i++)
				cin >> mn[i];
			Menu m(x, y, size, num, mn);
			m.Display();
			int p = m.SelectionMenu();
			m.Clear();
			cout << p << endl;
		}

		catch (ExMenu exp)
		{
			switch (exp.type)
			{
			case(Size):
				cout << "Error on size = " << exp.intSize << endl;
				break;
			case(outofAr):
				cout << "Size Array != Num String: Size Array = " << exp.intSize << endl;
				break;
			default:
				break;
			}
		}
	}
	_getch();
	return 0;
}
