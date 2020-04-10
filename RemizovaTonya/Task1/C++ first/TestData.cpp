#include "Data.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
int main()
{
	int numeric; // ѕеременна€ дл€ прибавлени€ или вычитани€ дней из даты
	int m[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int m1[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	Data date1;
	cout << "First date is a leap year ";
	date1.Print();
	Data date2(2, 3, 1999);
	cout << "Second date___Initialization ";
	date2.Print();
	Data date3(date2);
	cout << "Third date___Copy ";
	date3.Print();
	string line;
	cout << "Enter the date in a string in the format: dd/mm/yyyy" << endl;
	cin >> line;
	Data date4(line);
	cout << "Fourth date___String-->int ";
	if (date1 == date2)
		cout << "dates are equal" << endl;
	if (date1 != date2)
		cout << "dates are not equal" << endl;
	if (date1 > date2)
		cout << "first date is greatre than second" << endl;
	if (date1 < date2)
		cout << "first date is less than second" << endl;
	cout << "DATE ADDITION" << endl;
	cout << "Enter the number of days to be added to your date: ";
	cin >> numeric;
	cout << "Enter the date no earlier than 01.01.1000 to witch you want to add days: " << endl;
	date1 + numeric;
	cout << "DATE SABSTRACTION" << endl;
	cout << "Enter the number of days to be substructed from your date: ";
	cin >> numeric;
	cout << "Enter the date no earlier than 01.01.1970 from witch you want to substruct the days: " << endl;
	date1 - numeric;

}
