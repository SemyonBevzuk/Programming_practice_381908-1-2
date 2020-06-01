#include<iostream>
#include<sstream>
#include<vector>

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

    Time(const int16_t t_hours, const int16_t t_minutes, const int16_t t_seconds) : hours(t_hours), minutes(t_minutes), seconds(t_seconds) {}

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

class Date {
private:
    int16_t day, month, year;
    static const int COUNT_OF_MONTHS = 12;
    static const vector<int> COUNT_OF_DAYS;
public:
    
    Date() : day(1), month(1), year(0) {}

    Date(const int16_t t_day, const int16_t t_month, const int16_t t_year) {
        if (t_year >= 0 && t_month >= 1 && t_month <= COUNT_OF_MONTHS && t_day >= 1 && t_day <= COUNT_OF_DAYS[t_month - 1]) {
            day = t_day;
            month = t_month;
            year = t_year;
        }else {
            cout << "Invalid date\n";
        }
    }

    int16_t getDay() const {
        return day;
    }

    void setDay(int _day) {
        day = _day;
    }

    int16_t getMonth() const {
        return month;
    }

    void setMonth(int _month) {
        day = _month;
    }

    int16_t getYear() const {
        return year;
    }

    void setYear(int _year) {
        day = _year;
    }

    bool operator < (const Date& d) const {
        return (getYear() < d.getYear()) || (getYear() == d.getYear() && getMonth() < d.getMonth()) || (getYear() == d.getYear() && getMonth() == d.getMonth() && getDay() < d.getDay());
    }

    bool operator == (const Date& d) const {
        return (getYear() == d.getYear() && getMonth() == d.getMonth() && getDay() == d.getDay());
    }

    friend ostream& operator<<(ostream& out, const Date& date);
    friend istream& operator>>(istream& in, Date& date);
};

ostream& operator<<(ostream& out, const Date& date) {
    out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    return out;
}

istream& operator>>(istream& in, Date& date) {
    int _day, _year, _month;
    char dot;
    in >> _day >> dot >> _month >> dot >> _year;
    date.setDay(_day);
    date.setMonth(_month);
    date.setYear(_year);
    return in;
}

const vector<int> Date::COUNT_OF_DAYS = vector<int>{ 31, 30, 28, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class CinemaHall {
private:
    vector<vector<vector<bool> > > used;
    string nameOfFilm;
    Date date;
    Time time;

public:
    const int DEFAULT_SIZE = 5;

    Date getDate() const {
        return date;
    }

    void setDate(Date _date) {
        date = _date;
    }

    Time getTime() const {
        return time;
    }

    void setTime(Time _time) {
        time = _time;
    }

    string getNameOfFilm() const {
        return nameOfFilm;
    }

    void setNameOfFilm(string _name) {
        nameOfFilm = _name;
    }

    CinemaHall() {
        used.resize(2, vector<vector<bool> > (DEFAULT_SIZE, vector<bool> (DEFAULT_SIZE, false)));
        time = Time();
        date = Date();
        nameOfFilm = "Back to the future";
    }

    CinemaHall(const int width, const int height, const Date _date, const Time _time, const string _name) {
        used.resize(2, vector<vector<bool> >(height, vector<bool>(width, false)));
        date = _date;
        time = _time;
        nameOfFilm = _name;
    }

    vector<pair<int, int> > getPlaces(int count, int is_VIP = 0) {
        vector<pair<int, int> > result;
        for (size_t i = 0; i < used[is_VIP].size(); i++) {
            for (size_t j = 0; j < used[is_VIP][i].size(); j++) {
                if (!used[is_VIP][i][j]) {
                    if (result.size() < count) result.push_back({i + 1, j + 1});
                }
            }
        }
        // If we haven't enough places -- returning empty vector
        if (result.size() > count) {
            result.clear();
        }
        for (auto place : result) {
            used[is_VIP][place.first - 1][place.second - 1] = true;
        }
        return result;
    }

    void cancelPlaces(vector<pair<int,int> > &places, int is_VIP = 0) {
        for (auto place : places) {
            used[is_VIP][place.first - 1][place.second - 1] = false;
        }
    }

};

class Ticket {
private:
    Date date;
    Time time;
    string name;
    int16_t numberOfHall, row, place, isVIP;
    
public:

    Ticket(Date _date, Time _time, string _name, int16_t _numberOfHall, int16_t _row, int16_t _place, int16_t _isVIP) : date(_date), time(_time), name(_name), numberOfHall(_numberOfHall), row(_row), place(_place), isVIP(_isVIP) {}

    Ticket() : date(Date()), time(Time()), name("Back to the future"), numberOfHall(1), row(1), place(1), isVIP(0) {}

    string form() {
        stringstream ss;
        ss << "Date: " << date << ".\n";
        ss << "Time: " << time << ".\n";
        ss << "Name of film: " << name << ".\n";
        if (isVIP) {
            ss << "VIP Hall.\n";
        }
        ss << "Number of hall: " << numberOfHall << ".\n";
        ss << "Number of row and place: " << row << " row " << place << " place.";
        return ss.str();
    }

};

class Cinema {
private:
    vector<CinemaHall> halls;

public:
    const int CANT = -1;
    static const Time BEFORE_CLOSED, MORNING_CEIL, MIDDAY_CEIL;
    const int MORNING_PERCENT = 75, MIDDAY_PERCENT = 100, EVENING_PERCENT = 150, VIP_MULTIPLY = 2;
    const int PRICE = 200;
    

    enum TimeOfDay {
        MORNING,
        MIDDAY,
        EVENING,
    };

    TimeOfDay calcTime(const Time& time) const {
        if (time < MORNING_CEIL) return MORNING;
        if (time < MIDDAY_CEIL) return MIDDAY;
        return EVENING;
    }
    
    int calcPrice(const Time timeOfRegistration, const Time timeOfFilm, const Date dateOfRegistration, const Date dateOfFilm, const int isVIP = 0) {
        if ((dateOfRegistration < dateOfFilm) || (dateOfRegistration == dateOfFilm && ((timeOfRegistration < timeOfFilm) || (timeOfRegistration - timeOfFilm < BEFORE_CLOSED)))) { 
            auto timeOfDay = calcTime(timeOfFilm);
            int price = PRICE;
            if (isVIP) {
                price *= VIP_MULTIPLY;
            }
            switch (timeOfDay) {
            case MORNING:
                return price * MORNING_PERCENT / 100;
                break;
            case MIDDAY:
                return price * MIDDAY_PERCENT / 100;
                break;
            case EVENING:
                return price * EVENING_PERCENT / 100;
                break;
            }
        }else {
            return CANT;
        }
    }
    
    pair<vector<Ticket>, int> formTickets(const Date date, const Time time, const int count, const int numberOfHall, const int isVIP = 0) {
        if (numberOfHall < halls.size() && numberOfHall > 0) {
            auto price = calcPrice(time, halls[numberOfHall - 1].getTime(), date, halls[numberOfHall - 1].getDate(), isVIP);
            if (price == CANT) {
                return { vector<Ticket>(), CANT };
            }
            auto places = halls[numberOfHall - 1].getPlaces(count, isVIP);
            if (places.size() == count) {
                vector<Ticket> result;
                for (auto place : places) {
                    result.push_back(Ticket(halls[numberOfHall - 1].getDate(), halls[numberOfHall - 1].getTime(), halls[numberOfHall - 1].getNameOfFilm(), numberOfHall, place.first, place.second, isVIP));
                }
                return {result, price * result.size()};
            }else {
                return {vector<Ticket>(), CANT};
            }
        }else {
            return {vector<Ticket>(), CANT};
        }
    }

    void cancelTickets(int numberOfHall, vector<pair<int, int> >& places, int isVIP = 0) {
        if (numberOfHall < halls.size() && numberOfHall > 0) {
            halls[numberOfHall - 1].cancelPlaces(places, isVIP);
        }
    }
};

const Time Cinema::BEFORE_CLOSED = Time(0, 10, 0);
const Time Cinema::MORNING_CEIL = Time(12, 0, 0);
const Time Cinema::MIDDAY_CEIL = Time(18, 0, 0);

class TicketOffice {
           
};

int main()
{
    
}