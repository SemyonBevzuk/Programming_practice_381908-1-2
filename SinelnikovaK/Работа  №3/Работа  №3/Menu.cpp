#include "Menu.h";
#include <fstream>
#include <conio.h>
using namespace std;

//конструктор по умолчанию, конструктор-инициализатор
Menu::Menu(string* nas, int xpos, int ypos, int ss, int l)
{
	x = xpos;
	y = ypos;
	size = ss;
	menu = new string[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		menu[i] = nas[i] + ' ';
	}
	int l2 = XofI(size) - 1;
	if (l2 <= l)
		length = l;
	else
		length = l2;
}

//конструктор копирования
Menu::Menu(const Menu& m)
{
	x = m.x;
	y = m.y;
	size = m.size;
	length = m.length;
	menu = new string[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		menu[i] = m.menu[i];
	}
}

//конструктор из файла
Menu::Menu(string file)
{
	ifstream strIn(file);
	strIn >> x >> y >> length >> size;
	menu = new string[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		strIn >> menu[i];
	}
	strIn.close();
	int l2 = XofI(size) - x;
	if (l2 > length)
		length = l2;
}

//деструктор
Menu::~Menu()
{
	if (menu != NULL)
		delete[] menu;
	size = 0;
	x = y = length = 0;
}

//метод показать меню
void Menu::Show()
{
	clrscr();
	setwindow(length + x, 30);
	gotoxy(x, y);
	for (int i = 0; i < size; i++)
	{
		cout << menu[i] << ' ';
	}
	gotoxy(x, y);
}

int Menu::GetY()
{
	return y;
}
int Menu::GetX()
{
	return x;
}

//метод удалить меню с экрана
void Menu::Del()
{
	int x0 = wherex();
	int y0 = wherey();
	gotoxy(x, y);
	for (int i = 0; i < length; i++)
	{
		cout << " ";
	}
	gotoxy(x0, y0);
}

//выбрать пункт меню стрелочками
void Menu::ToLToR(int ch)
{
	int SI = SelectI();
	if (SI == -1) return;
	if (ch == 224) return;
	if (ch == 75 && SI > 0)
	{
		gotoxy(XofI(SI - 1), y);
	}
	else
		if (ch == 77 && SI < size - 1)
		{
			gotoxy(XofI(SI + 1), y);
		}
		else
			if (ch == 13)
			{
				gotoxy(0, y + 1);
				cout << "Номер, выбранного пункта меню: " << SI + 1 << endl;
			}

}

int Menu::XofI(int ipos)
{
	int xp = x;
	for (int i = 0; i < ipos; i++)
	{
		xp += menu[i].length() + 1;
	}
	return xp;
}

int Menu::SelectI()
{
	int xpos = wherex(), ypos = wherey();
	if (ypos != y || xpos < x || xpos >= x + length) return -1;
	int xm = x;
	for (int i = 0; i < size; i++)
	{
		int ll = menu[i].length() + 1;
		if (xpos >= xm && xpos < xm + ll)
		{
			return i;
		}
		else
		{
			xm += ll;
		}
	}
	return -1;
}

//добавить пункт меню

void Menu::AddItem(string newitem)
{
	for (int i = 0; i < size; i++)
	{
		if (menu[i] == newitem)
		{
			cout << "Такой пункт меню уже существует" << endl;
			return;
		}
	}
	string* newmenu = new string[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		newmenu[i] = menu[i];
	}
	newmenu[size] = newitem;
	Menu res(newmenu, x, y, size + 1, length);
	*this = res;
}

Menu& Menu::operator=(const Menu& m)
{
	if (this == &m) return *this;
	x = m.x;
	y = m.y;
	size = m.size;
	length = m.length;
	for (int i = 0; i < size; i++)
	{
		menu[i] = m.menu[i];
	}
	return *this;
}


//удалить пункт меню
void Menu::DelItem(int idel)
{
	idel--;
	if (idel < 0 || size <= idel)
	{
		cout << "Такого пункта меню не существует" << endl;
		return;
	}
	string* newmenu = new string[MAXSIZE];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != idel)
			newmenu[j++] = menu[i];
	}
	Menu res(newmenu, x, y, size - 1, length);
	*this = res;
}

void gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(Console, pos);
}
int wherex(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return -1;

	CONSOLE_SCREEN_BUFFER_INFO buf;

	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition.X;
}
int wherey(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return -1;

	CONSOLE_SCREEN_BUFFER_INFO buf;

	GetConsoleScreenBufferInfo(Console, &buf);
	return buf.dwCursorPosition.Y;
}
void clrscr(void)
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
	int width = buf.dwSize.X;
	int height = buf.dwSize.Y;

	COORD zpos;
	zpos.X = 0;
	zpos.Y = 0;
	SetConsoleCursorPosition(Console, zpos);

	FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
	FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}
void setwindow(int width, int height)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = width - 1;
	rect.Top = 0;
	rect.Bottom = height - 1;
	COORD size;
	size.X = width;
	size.Y = height;
	SetConsoleWindowInfo(Console, true, &rect);
	SetConsoleScreenBufferSize(Console, size);
}
