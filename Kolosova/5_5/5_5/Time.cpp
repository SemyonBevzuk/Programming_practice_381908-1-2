#include "Time.h"
using namespace std;
int Days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Time::Time(){
	h = 0;
	m = 0;
}
Time::Time(const Time& t){
	h = t.h;
	m = t.m;
}
Time::Time(const int& hr, const int& min){
	h = hr;
	m = min;
}
int Time::get_h() {
	return h;
}
int Time::get_m() {
	return m;
}
Time& Time::operator=(const Time& t){
	h = t.h;
	m = t.m;
	return *this;
}
Time Time::operator+(const Time& t){
	Time res;
	res.m = t.m + m;
	res.h = (t.h + h + res.m / 60)%24;
	res.m %= 60;
	return res;
}
Time Time::operator-(const Time& t){
	Time res;
	res.m = m - t.m;
	res.h = h - t.h;
	if (res.m < 0) {
		res.h--;
		res.m += 60;
	}
	return res;
}
bool Time::operator<(const Time& t){
	return ((h < t.h) || (h == t.h) && (m < t.m))?true:false;
}
bool Time::operator>(const Time& t){
	return ((h > t.h) || (h == t.h) && (m > t.m)) ? true : false;
}
bool Time::operator>(Time& t) const{
	return ((h > t.h) || (h == t.h) && (m > t.m)) ? true : false;
}
bool Time::operator<=(const Time& t){
	return ((h <= t.h) || (h == t.h) && (m <= t.m)) ? true : false;
}
bool Time::operator>=(const Time& t){
	return ((h >= t.h) || (h == t.h) && (m >= t.m)) ? true : false;
}
bool Time::operator==(const Time& t){
	return ((h == t.h) && (m == t.m)) ? true:false;
}
bool Time::operator!=(const Time& t) {
	return !(*this == t);
}
Time& Time::operator+=(const Time& t){
	*this = *this + t;
	return *this;
}
Time& Time::operator-=(const Time& t){
	* this = *this - t;
	return *this;
}
///////////////////////////////////////

istream& operator>>(istream& in, Time& t){
	in >> t.h >> t.m ;
	while ((t.h < 0) || (t.h > 24) || (t.m < 0) || (t.m > 60)) {
		cout << "Incorrect time input. Try again:\n";
		in >> t.h >>t.m ;
	}
	return in;
}
ostream& operator<<(ostream& out, const Time &t){
	out << t.h << ':' << t.m;
	return out;
}
ifstream& operator>>(ifstream& in, Time& a) {
	in >> a.h >> a.m;
	return in;
}
ofstream& operator<<(ofstream& out, const Time& a) {
	out << a.h << ' ' << a.m;
	return out;
}
Time::~Time() {}

ostream& operator<<(ostream& out, const Date& d) {
	out << d.d << '.' << d.m << '.'<<d.y;
	return out;
}
istream& operator>>(istream& in, Date& d) {
	in >> d.d >> d.m >> d.y;
	return in;
}
ofstream& operator<<(ofstream& out, const Date& d) {
	out << d.d << ' ' << d.m << ' ' << d.y;
	return out;
}
ifstream& operator>>(ifstream& in, Date& d) {
	in >> d.d >> d.m >> d.y;
	return in;
}
Date::Date() {}
Date Date::operator+(const int a)const{
	Date d1(*this);
	d1.d +=a;
	if (d1.d > Days1[d1.m - 1]) {

		while (d1.d > Days1[d1.m - 1]) {
			if ((d1.m == 2) && ((d1.y % 4) && (!d1.y % 100) || (d1.y % 400))) {
				d1.d -= 29;
				d1.m++;
			}
			else {
				d1.d -= Days1[(d1.m - 1) % 12];
				if (d1.m == 12) {
					d1.m = 1;
					d1.y++;
				}
				else d1.m++;
			}
		}
	}
	return d1;
}