#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
private:
	int _day;
	int _month;
	int _year;
public:
	Date(int d = 1, int m = 1, int y = 1000);
	Date(const Date& date);
	int getDay() const { return _day; }
	int getMonth() const { return _month; }
	int getYear() const { return _year; }
	Date getDate() const { return *this; }
	string getDateToString() const;
	bool setDay(int d);
	bool setMonth(int m);
	bool setYear(int y);
	bool setDate(int day, int month, int year);
	Date& operator=(const Date& date);
	bool operator == (const Date& date) const;
};

#endif 
