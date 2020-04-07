#ifndef FILM_H
#define FILM_H

#include "Date.h"
#include <string>
#include<iostream>

using namespace std;

class Film {
private:
	string _name;
	string _producer;
	string _screenwriter;
	string _composer;
	Date _date;
	long long _value;
public:
	Film(string name = "Not Found", string producer = "Not Found",
		string screenwriter = "Not Found", string composer = "Not Found",
		Date date = Date(), long long value = -1);
	string getName() const { return _name; }
	string getProducer() const { return _producer; }
	string getScreenwriter() const { return _screenwriter; }
	string getComposer() const { return _composer; }
	Date getDate() const {return _date.getDate();}
	string getDateToString() const { return _date.getDateToString(); }
	long long getValue() const { return _value; }
	void setName(string name);
	void setProducer(string producer);
	void setScreenwriter(string screenwriter);
	void setComposer(string composer);
	bool setDate(int day, int month, int year) {return _date.setDate(day, month, year); }
	bool setValue(long long value);
	Film& operator=(const Film& f);
	friend ostream& operator<<(ostream& stream, const Film& film);
	friend istream& operator>>(istream& stream, Film& film);
};
#endif
