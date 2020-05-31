#include "DateTime.h"
#include <string>

DateTime::DateTime()
{
}

bool DateTime::operator==(const DateTime& theOp)
{
    return myYear == theOp.myYear && myMonth == theOp.myMonth && myDay == theOp.myDay && myHour == theOp.myHour && myMinute == theOp.myMinute;
}

bool DateTime::operator!=(const DateTime& theOp)
{
    return !(operator==(theOp));
}

int DateTime::operator-(const DateTime& theOp)
{
    int myMinutes = (((myYear * 12 + myMonth) * 30 + myDay) * 24 + myHour) * 60;
    int opMinutes = (((theOp.myYear * 12 + theOp.myMonth) * 30 + theOp.myDay) * 24 + theOp.myHour) * 60;
    return myMinute - opMinutes;
}

string DateTime::ToString()
{
    return "" + to_string(myYear) + "." + to_string(myMonth) + "." + to_string(myDay) + " " + to_string(myHour) + ":" + to_string(myMinute);
}

double DateTime::MinuteToHours(int theMinutes)
{
    return (double)theMinutes/60;
}

double DateTime::HoursToDays(int theHours)
{
    return (double)theHours/24;
}
