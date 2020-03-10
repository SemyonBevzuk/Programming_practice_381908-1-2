#include "Data.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
int main()
{
	int numeric; // ѕеременна€ дл€ прибавлени€ или вычитани€ дней из даты
	string line = "12.11.2002";
	Data date1;
	Data date2(2, 3, 1999);
	Data date3(date2);
	Data date4(line);
	cout << "First date is a leap year ";
	date1.Print();
	cout << "Second date___Initialization ";
	date2.Print();
	cout << "Third date___Copy ";
	date3.Print();
	cout << "Fourth date___String ";
	date4.Print();
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
