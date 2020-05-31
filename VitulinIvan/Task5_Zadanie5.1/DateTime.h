#pragma once
#include <iostream>


using namespace std;

class DateTime
{
public:
    int myHour;
    int myMinute;
    int myDay;
    int myMonth;
    int myYear;
    DateTime();
    DateTime(int theYear, int theMonth, int theDay, int theHour = 0, int theMinute = 0) :
        myYear(theYear), myMonth(theMonth), myDay(theDay), myHour(theHour), myMinute(theMinute) {}
    bool operator==(const DateTime& theOp);
    bool operator!=(const DateTime& theOp);
    int operator- (const DateTime& theOp);// return minutes
    string ToString();
    static double MinuteToHours(int theMinutes);
    static double HoursToDays(int theHours);
};

