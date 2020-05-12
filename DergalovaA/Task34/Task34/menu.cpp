#include "Menu.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>


void gotoxy(int x, int y) // cursor changes the position
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(Console, pos);
}

COORD WhereXY(void) // cursor search
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { -1, -1 };
	if (!Console)
		return pos;

	CONSOLE_SCREEN_BUFFER_INFO buf;

	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition;
}

void Menu::Clear() // delete menu
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	WORD Attr;
	DWORD Count;
	COORD pos = buf.dwCursorPosition;
	ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

	int col = Attr;
	int width = size;
	int height = 1;

	COORD zpos;
	zpos.X = xCor;
	zpos.Y = yCor;
	SetConsoleCursorPosition(Console, zpos);

	FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
	FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}

Menu::Menu() 
{
	xCor = 0;
	yCor = 0;
	size = 0;
	numMenu = 0;
	menu = NULL;
}

Menu::Menu(int x, int y, int sz, int num, string* Mn)
{
	xCor = x;
	yCor = y;
	size = sz;
	numMenu = num;
	menu = new string[numMenu];
	int s = 0;
	for (int i = 0; i < numMenu; i++)
	{
		menu[i] = Mn[i];
		s += menu[i].length();
	}
	if (s > size)
		throw ExMenu(Size, size);
}

Menu::Menu(const Menu& m)
{
	xCor = m.xCor;
	yCor = m.yCor;
	size = m.size;
	numMenu = m.numMenu;
	menu = new string[numMenu];
	for (int i = 0; i < numMenu; i++)
		menu[i] = m.menu[i];
}

Menu::Menu(string nameMenu) //from file
{

	ifstream ostr;
	ostr.open(nameMenu);
	ostr >> xCor >> yCor >> size >> numMenu;
	menu = new string[numMenu];
	int s = 0;

	for (int i = 0; i < numMenu; i++)
	{
		if (!ostr.eof() && i < numMenu)
		{
			ostr >> menu[i];
			s += menu[i].length();
		}
		else
			throw ExMenu(outofAr, numMenu);
	}

	if (s > size)
		throw ExMenu(Size, s);

	ostr.close();

}

Menu::~Menu()
{
	xCor = 0;
	yCor = 0;
	numMenu = 0;
	size = 0;
	delete[] menu;
}

void Menu::Display()
{
	gotoxy(xCor, yCor);
	for (int i = 0; i < numMenu; i++)
	{
		cout << menu[i];
		int k = size / numMenu - menu[i].length();
		for (int j = 0; j < k; j++)
			cout << " ";
	}
}

int Menu::SelectionMenu()
{
	COORD position = { xCor ,yCor };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	bool exit = false;
	int ch;
	while (!exit)
	{
		ch = _getch();
		switch (ch)
		{
		case 224:
		{
			switch (_getch())
			{
			case 75:
			{// "<-" pressed
				if (position.X <= xCor + size && position.X > xCor)
				{
					position.X--;
					SetConsoleCursorPosition(hConsole, position);
				}

				break;
			}
			case 77:
			{// "->" pressed
				if (position.X < xCor + size - 1 && position.X >= xCor)
				{
					position.X++;
					SetConsoleCursorPosition(hConsole, position);
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 13:
		{
			//enter pressed

			int xm = xCor;
			int ym = yCor;
			//coords of the menu

			// search of the selected point
			for (int i = 0; i < numMenu; i++)
			{
				if (position.X >= xm && position.X < xm + menu[i].length())
				{
					exit = true;
					return i + 1;
				}
				else
				{ // skip the point
					xm += (size / numMenu);
				}
			}
			break;
		}
		default:
			break;
		}
	}
}