#include "Menu.h";
#include <conio.h>

int main()
{
	SetConsoleOutputCP(1251);
	Menu m1("f1.txt");
	std::cout << "help - помощь" << endl << "Введите команду> ";
	string xD;
	cin >> xD;
	while (xD != "exit")
	{
		if (xD == "help")
		{
			std::cout << "help - помощь" << endl << "exit - выход" << endl << "delmenu - удалить меню с консоли" << endl << "clear - очистить экран" << endl << " add- добавить пункт меню" << endl << "delitem - удалить пункт меню" << endl << "show - показать меню" << endl;
		}
		else
			if (xD == "show")
			{
				m1.Show();
				while (wherey() == m1.GetY())
					m1.ToLToR(_getch());
			}
			else
				if (xD == "clear")
				{
					clrscr();
				}
				else
					if (xD == "add")
					{
						string s2;
						std::cout << "Введите название пункта меню, который вы хотите добавить ";
						cin >> s2;
						m1.AddItem(s2);
					}
					else
						if (xD == "delmenu")
						{
							m1.Del();
						}
						else
							if (xD == "delitem")
							{
								std::cout << "Введите пункт меню, который вы хотите удалить ( нумерация идёт с 1 )";
								int k;
								cin >> k;
								m1.DelItem(k);
							}
		std::cout << "Введите команду> ";
		cin >> xD;
	}
	std::cout << "Завершение работы";
	return 0;
}

