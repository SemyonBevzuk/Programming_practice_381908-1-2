#pragma once
#include <iostream>
#include <cstdlib>
#include <locale>
#include "windows.h"
#include "stdio.h"
#include "memory.h"
using namespace std;
constexpr int MAXSIZE = 50;
class Menu
{
private:
	int x, y, length;
	int size;
	string* menu;
	int SelectI();
	int XofI(int ipos);
public:
	Menu(string* nas = NULL, int xpos = 1, int ypos = 1, int ss = 1, int l = 80);
	Menu(string file);
	Menu(const Menu& m);
	~Menu();
	void Show();
	void Del();
	void ToLToR(int ch);
	int GetY();
	int GetX();
	void AddItem(string newitem);
	void DelItem(int idel);
	Menu& operator=(const Menu& m);
};
int wherex(void);
void gotoxy(int x, int y);
int wherey(void);
void clrscr(void);
void setwindow(int width, int height);


