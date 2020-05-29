#include "ClassContacts.h"
#include "ClassMainMenu.h"
#include <iostream>
#include <clocale>


using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
    MainMenu menu;
    menu.Start();
}