#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum ExacetionSong { notSong, notSinger, notComposer, notAuthor, outOfArr };

struct ExSong
{
	ExacetionSong type;
	int intSize;
	ExSong(ExacetionSong _type, int _intSize)
	{
		type = _type;
		intSize = _intSize;
	}
};

class Song
{
private:
	string title;
	string author;
	string composer;
	string singer;
	string albumTitle;
	int day, month, year;
public:
	Song();
	Song(string tl, string auth, string com, string sing, string albt, int d, int m, int y);
	~Song();
	void SetTitle(string _title) { title = _title; }
	void SetAuthor(string _author) { author = _author; }
	void SetComposer(string _composer) { composer = _composer; }
	void SetSinger(string _singer) { singer = _singer; }
	void SetAlbumTitle(string _albumTitle) { albumTitle = _albumTitle; }
	void SetDay(int _day) { day = _day; }
	void SetMonth(int _month) { month = _month; }
	void SetYear(int _year) { year = _year; }

	string GetTitle() const { return title; }
	string GetAuthor() const { return author; }
	string GetComposer() const { return composer; }
	string GetSinger() const { return singer; }
	string GetAlbumTitle() const { return albumTitle; }
	int GetDay() const { return day; }
	int GetMonth() const { return month; }
	int GetYear() const { return year; }
};

class Songs
{
private:

	int songCount;
	int bufCount;
	Song* song;
	void Assignment(int ip, string tl, string auth, string com, string sing, string albt, int d, int m, int y);

public:

	Songs(); //default
	Songs(Songs& s); // copy
	Songs(string txtFile); // from file
	Songs(int size, int bufsize, Song* s);
	~Songs();

	void Save(string txtFile);
	void Open(string txtFile);
	void Add(string tl, string auth, string com, string sing, string albt, int d, int m, int y);
	void Edit(string tlNow, string tl, string auth, string com, string sing, string albt, int d, int m, int y);

	Songs Search(string tl, string sing);
	Songs AllSongAuthor(string auth);
	Songs AllSongComposer(string com);
	Songs AllSongSinger(string sing);
	int NumOfSongs();
	void Remove(string tl);

	Songs& operator=(const Songs& s);

	friend ostream& operator <<(ostream& stream, const Song& s);
	friend istream& operator >>(istream& stream, Song& s);
};

ostream& operator <<(ostream& stream, const Song& s);
istream& operator >>(istream& stream, Song& s);
