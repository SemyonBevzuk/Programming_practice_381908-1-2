#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

enum ExceptionType { Size, outofAr};
struct ExMenu 
{
	ExceptionType type;
	int intSize;
	ExMenu(ExceptionType _type, int _intSize)
	{
		type = _type;
		intSize = _intSize;
	}
};


class Menu
{
private:
	int xCor;
	int yCor;
	int size;
	int numMenu;
	string* menu;

public:
	Menu();
	Menu(int x, int y, int sz, int num, string* Mn);
	Menu(const Menu& m);
	Menu(string nameMenu);
	~Menu();

	void Display();
	void Clear();
	int SelectionMenu();
};