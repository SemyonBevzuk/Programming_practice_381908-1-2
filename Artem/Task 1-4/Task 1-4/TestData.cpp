#include"Data.h"
#include<iostream>
using namespace std;

int main()
{
	Data date1, date2(06, 03, 2020), date3(date2), date4;
	int days;
	cout << "Enter the fourth date:";
	cin >> date4;
	cout << "The fourth date is " << date4 << endl;
	cout << "Enter the amount of days: "  ;
	cin >> days;

	date1 -= days;
	cout << date1;
	date2 = date1;
	cout << date4 << endl;
	date4 += days;
	cout << date4;

	system("pause");
	return 0;

}