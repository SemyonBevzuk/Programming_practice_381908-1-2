﻿#include "Songs.h"

Songs::Songs()
{
}

Songs::~Songs()
{
}

void Songs::AddSong(Song S)
{
	songs.push_back(S);
}

void Songs::ChangeSong(string title, char ch, string info, Date date)
{
	Song S;
	S.title = title;
	songs.push_back(S);
	int i = 0;
	while (songs[i].title != title) i++;
	songs.pop_back();
	if (i < songs.size())
		switch (ch)
		{
		case 't':
			songs[i].title = info;
			break;
		case 'p':
			songs[i].poet = info;
			break;
		case 'c':
			songs[i].composer = info;
			break;
		case 's':
			songs[i].singer = info;
			break;
		case 'a':
			songs[i].album = info;
			break;
		case 'd':
			songs[i].date = date;
			break;
		}
}

Song Songs::FindSong(string title, string singer) const
{
	Song S;
	S.title = title;
	S.singer = singer;
	const_cast<vector<Song>&>(songs).push_back(S);
	int i = 0;
	while (songs[i].title != title || songs[i].singer != singer) i++;
	const_cast<vector<Song>&>(songs).pop_back();
	if (i < songs.size()) return songs[i];
	return Song();
}

vector<Song> Songs::AllByPoet(string poet) const
{
	vector<Song> vec;
	int size = songs.size();
	for (int i = 0; i < size; i++)
		if (songs[i].poet == poet)
			vec.push_back(songs[i]);
	return vec;
}

vector<Song> Songs::AllByComposer(string composer) const
{
	vector<Song> vec;
	int size = songs.size();
	for (int i = 0; i < size; i++)
		if (songs[i].composer == composer)
			vec.push_back(songs[i]);
	return vec;
}

vector<Song> Songs::AllBySinger(string singer) const
{
	vector<Song> vec;
	int size = songs.size();
	for (int i = 0; i < size; i++)
		if (songs[i].singer == singer)
			vec.push_back(songs[i]);
	return vec;
}

int Songs::GetSize() const
{
	return songs.size();
}

void Songs::Delete(string title)
{
	Song S;
	S.title = title;
	songs.push_back(S);
	int i = 0;
	while (songs[i].title != title) i++;
	songs.pop_back();
	int size = songs.size();
	if (i < size)
	{
		for (; i < size - 1; i++)
			songs[i] = songs[i + 1];
		songs.pop_back();
	}
}

ofstream & operator<<(ofstream & out, const Songs & S)
{
	int n = S.GetSize();
	out << n << endl;
	for (int i = 0; i < n; i++)
		out << S.songs[i];
	return out;
}

ifstream & operator>>(ifstream & in, Songs & S)
{
	int n;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> S.songs[i];
	return in;
}
