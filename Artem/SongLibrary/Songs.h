#pragma once
#ifndef INCLUDE_CLASS_MEDIAPLAYER_H_
#define INCLUDE_CLASS_MEDIAPLAYER_H_
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>

using namespace std;

class Song {
private:
	string sname;
	string author;
	string composer;
	string singer;
	string album;
	string date;
public:
	Song() {};
	Song(string _sname, string _author, string _composer, string _singer, string _album, string _date);

	string Get_Sname() const { return sname; }
	string Get_Author() const { return author; }
	string Get_Composer() const { return composer; }
	string Get_Singer() const { return singer; }
	string Get_Album() const { return album; }
	string Get_Date() const { return date; }

	void Set_Sname(string _sname);
	void Set_Author(string _author);
	void Set_Composer(string _composer);
	void Set_Singer(string _singer);
	void Set_Album(string _album);
	void Set_Date(string _date);

	friend bool operator==(const Song& left, const Song& right);
};

class MediaPlayer {
private:
	Song* arr;
	int size;
public:
	MediaPlayer();
	MediaPlayer(const Song _song);
	MediaPlayer(const MediaPlayer& player);
	~MediaPlayer();

	void PrintSongInfo(int index);
	void Add(string a, string b, string c, string d, string e, string f);
	void AuthorSongs(string a);
	void ComposerSongs(string a);
	void SingerSongs(string a);
	void Delete(int index);
	void Load();
	void Read();
	void ChangeSongInfo(int a, string _author, string _composer, string _singer, string _album, string _date);
	int NumberOfSongs();

	int index_of_Song_name(string a);
	int index_of_Song_name_and_singer(string a, string b);
};

#endif INCLUDE_CLASS_MEDIAPLAYER_H_