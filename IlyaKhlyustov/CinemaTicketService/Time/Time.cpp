#include<iostream>
#include<sstream>

using namespace std;

class Time {
private:
    int16_t hours, minutes, seconds;

public:

    static const int16_t HOURS_PER_DAY = 24, MINUTES_PER_HOUR = 60, SECONDS_PER_MINUTE = 60;

    Time() : hours(0), minutes(0), seconds(0) {}

    Time(string time) {
        setTime(time);
        normalize();
    }

    Time(int16_t t_hours, int16_t t_minutes, int16_t t_seconds) : hours(t_hours), minutes(t_minutes), seconds(t_seconds) {}

    void normalize() {
        setMinutes(getMinutes() + getSeconds() / Time::SECONDS_PER_MINUTE);
        setHours(getHours() + getMinutes() / Time::MINUTES_PER_HOUR);
        hours %= HOURS_PER_DAY;
        minutes %= MINUTES_PER_HOUR;
        seconds %= SECONDS_PER_MINUTE;
    }

    bool operator < (const Time& f) const {
        return (getHours() < f.getHours()) || (getHours() == f.getHours() && getMinutes() < f.getMinutes()) || (getHours() == f.getHours() && getMinutes() == f.getMinutes() && getSeconds() < f.getSeconds());
    }

    void setTime(string time) {
        stringstream timeStream;
        timeStream << time;
        char doubleDot;
        int16_t t_hours, t_minutes, t_seconds;
        timeStream >> t_hours >> doubleDot >> t_minutes >> doubleDot >> t_seconds;
        setHours(t_hours);
        setMinutes(t_minutes);
        setSeconds(t_seconds);
        normalize();
        timeStream.clear();
    }
    
    int16_t getHours() const {
        return hours;
    }

    void setHours(int16_t newHours) {
        hours = newHours;
    }

    int16_t getMinutes() const {
        return minutes;
    }

    void setMinutes(int16_t newMinutes) {
        minutes = newMinutes;
    }

    int16_t getSeconds() const {
        return seconds;
    }

    void setSeconds(int8_t newSeconds) {
        seconds = newSeconds;
    }

    friend Time operator+(const Time& a, const Time& b);
    friend Time operator-(const Time& a, const Time& b);
    friend ostream& operator << (ostream& out, const Time& time);
    friend istream& operator >> (istream& in, Time& time);
    Time& operator= (const Time& time) = default;
    
};

ostream& operator << (ostream& out, const Time& time) {
    out << time.getHours() << ':' << time.getMinutes() << ':' << time.getSeconds();
    return out;
}

istream& operator >> (istream& in, Time& time) {
    char doubleDot;
    in >> time.hours >> doubleDot >> time.minutes >> doubleDot >> time.seconds;
    return in;
}

Time operator+(const Time& a, const Time& b) {
    Time result(a.getHours() + b.getHours(), a.getMinutes() + b.getMinutes(), a.getSeconds() + b.getSeconds());
    result.normalize();
    return result;
}

Time operator-(const Time& a, const Time& b) {
    Time result(a.getHours() - b.getHours(), a.getMinutes() - b.getMinutes(), a.getSeconds() - b.getSeconds());
    
    if (result.getSeconds() < 0) {
        result.setSeconds(result.getSeconds() + Time::SECONDS_PER_MINUTE);
        result.setMinutes(result.getMinutes() - 1);
    }

    if (result.getMinutes() < 0) {
        result.setMinutes(result.getMinutes() + Time::MINUTES_PER_HOUR);
        result.setHours(result.getHours() - 1);
    }

    if (result.getHours() < 0) result.setHours(result.getHours() + Time::HOURS_PER_DAY);
    
    return result;
}


int main() {
    Time time1("12:30:00");
    Time time2(12, 30, 0);
    Time time3 = time1 + time2;
    Time time4 = time1 - time2;
    cout << time1 << '\n' << time2 << '\n' << time3 << '\n' << time4;
    return 0;
}