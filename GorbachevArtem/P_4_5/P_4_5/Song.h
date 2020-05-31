#pragma once
#include "Date.h"
#include <string>

struct Song
{
	string title;
	string poet;
	string composer;
	string singer;
	string album;
	Date date;

	friend ostream& operator<<(ostream& out, const Song& S);
	friend ofstream& operator<<(ofstream& out, const Song& S);
	friend ifstream& operator>>(ifstream& in, Song& S);
};

inline ostream & operator<<(ostream & out, const Song & S)
{
	out << S.title << endl;
	out << S.poet << endl;
	out << S.composer << endl;
	out << S.singer << endl;
	out << S.album << endl;
	out << S.date << endl;
	return out;
}

inline ofstream& operator<<(ofstream& out, const Song& S)
{
	out << S.title << endl;
	out << S.poet << endl;
	out << S.composer << endl;
	out << S.singer << endl;
	out << S.album << endl;
	out << S.date << endl;
	return out;
}

inline ifstream& operator>>(ifstream& in, Song& S)
{
	in >> S.title >> S.poet >> S.composer >> S.singer >> S.album >> S.date;
	return in;
}