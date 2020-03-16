//
// Created by Kirill Lakhov on 14.03.2020.
//

#ifndef TASK4_DATE_H
#define TASK4_DATE_H

#include "string"
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
    string sDay;
    string sMonth;
    string sYear;
public:
    Date(int d=1, int m=1, int y=1900);
    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);
    string getDate();
};


#endif //TASK4_DATE_H
