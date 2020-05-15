#include "Songs.h"
#include <fstream>
#include <sstream>
#include <iostream>


Song::Song()
{
	title = ""; author = ""; composer = ""; singer = ""; albumTitle = "";
	day = 0; month = 0; year = 0;
}

Song::Song(string tl, string auth, string com, string sing, string albt, int d, int m, int y)
{
	title = tl;
	author = auth;
	composer = com;
	singer = sing;
	albumTitle = albt;
	day = d;
	month = m;
	year = y;
}

Song::~Song()
{
	title = "";
	author = "";
	composer = "";
	singer = "";
	albumTitle = "";
	day = 0;
	month = 0;
	year = 0;
}

void Songs::Assignment(int ip, string tl, string auth, string com, string sing, string albt, int d, int m, int y)
{
	song[ip].SetTitle(tl);
	song[ip].SetAuthor(auth);
	song[ip].SetComposer(com);
	song[ip].SetSinger(sing);
	song[ip].SetAlbumTitle(albt);
	song[ip].SetDay(d);
	song[ip].SetMonth(m);
	song[ip].SetYear(y);
}

Songs::Songs()
{
	songCount = 0;
	bufCount = 0;
	song = nullptr;
}

Songs::Songs(Songs& s)
{
	songCount = s.songCount;
	bufCount = s.bufCount;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
		Assignment(i, s.song[i].GetTitle(), s.song[i].GetAuthor(), s.song[i].GetComposer(), s.song[i].GetSinger(), s.song[i].GetAlbumTitle(), s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
}

Songs::Songs(string txtFile)
{
	ifstream str;
	str.open(txtFile);
	if (!str.eof())
		str >> songCount;
	else
		throw ExSong(outOfArr, songCount);
	bufCount = songCount + 20;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
	{
		if (!str.eof())
			str >> song[i];
		else throw ExSong(outOfArr, songCount);
	}
	str.close();
}

Songs::Songs(int size, int bufsize, Song* s)
{
	songCount = size;
	bufCount = bufsize;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
		song[i] = s[i];
}

Songs::~Songs()
{
	songCount = 0;
	bufCount = 0;
	delete[] song;
}

void Songs::Save(string txtFile)
{
	ofstream stream;
	stream.open(txtFile);
	stream << songCount << endl;
	for (int i = 0; i < songCount; i++)
	{
		stream << song[i] << endl;
	}
	stream.close();
}

void Songs::Open(string txtFile)
{
	ifstream stream;
	stream.open(txtFile);
	stream >> songCount;
	bufCount = songCount + 20;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
	{
		stream >> song[i];
	}
	stream.close();
}

void Songs::Add(string tl, string auth, string com, string sing, string albt, int d, int m, int y)
{
	songCount++;
	if (songCount < bufCount)
	{
		Assignment(songCount - 1, tl, auth, com, sing, albt, d, m, y);
	}
	else
	{
		bufCount += 20;
		Song* s = new Song[songCount];
		for (int i = 0; i < songCount - 1; i++)
		{
			s[i].SetTitle(song[i].GetTitle());
			s[i].SetAuthor(song[i].GetAuthor());
			s[i].SetComposer(song[i].GetComposer());
			s[i].SetSinger(song[i].GetSinger());
			s[i].SetAlbumTitle(song[i].GetAlbumTitle());
			s[i].SetDay(song[i].GetDay());
			s[i].SetMonth(song[i].GetMonth());
			s[i].SetYear(song[i].GetYear());
		}
		delete[] song;
		song = new Song[bufCount];
		for (int i = 0; i < songCount - 1; i++)
			Assignment(i, s[i].GetTitle(), s[i].GetAuthor(), s[i].GetComposer(), s[i].GetSinger(), s[i].GetAlbumTitle(), s[i].GetDay(), s[i].GetMonth(), s[i].GetYear());
		delete[] s;
		Assignment(songCount - 1, tl, auth, com, sing, albt, d, m, y);
	}
}

void Songs::Edit(string tlNow, string tl, string auth, string com, string sing, string albt, int d, int m, int y)
{
	bool fl = true;
	for (int i = 0; i < songCount; i++)
	{
		if (song[i].GetTitle() == tlNow)
		{
			fl = false;
			Assignment(i, tl, auth, com, sing, albt, d, m, y);
			break;
		}
	}
	if (fl)
		throw ExSong(notSong, 0);
}

Songs Songs::Search(string tl, string sing)
{
	Songs s;
	for (int i = 0; i < songCount; i++)
	{
		if (song[i].GetTitle() == tl && song[i].GetSinger() == sing)
		{
			s.Add(song[i].GetTitle(), song[i].GetAuthor(), song[i].GetComposer(), song[i].GetSinger(), song[i].GetAlbumTitle(), s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
		}
	}

	if (!s.songCount)
		throw ExSong(notSong, songCount);
	return s;
}

Songs Songs::AllSongAuthor(string auth)
{
	Songs s;
	for (int i = 0; i < songCount; i++)
	{
		if (song[i].GetAuthor() == auth)
		{
			s.Add(song[i].GetTitle(), song[i].GetAuthor(), song[i].GetComposer(), song[i].GetSinger(), song[i].GetAlbumTitle(), s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
		}
	}
	if (!s.songCount)
		throw ExSong(notAuthor, songCount);
	return s;
}


Songs Songs::AllSongComposer(string com)
{
	Songs s;
	for (int i = 0; i < songCount; i++)
	{
		if (song[i].GetComposer() == com)
		{
			s.Add(song[i].GetTitle(), song[i].GetAuthor(), song[i].GetComposer(), song[i].GetSinger(), song[i].GetAlbumTitle(), s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
		}
	}
	if (!s.songCount)
		throw ExSong(notComposer, songCount);
	return s;
}

Songs Songs::AllSongSinger(string sing)
{
	Songs s;
	for (int i = 0; i < songCount; i++)
	{
		if (song[i].GetSinger() == sing)
		{
			s.Add(song[i].GetTitle(), song[i].GetAuthor(), song[i].GetComposer(), song[i].GetSinger(), song[i].GetAlbumTitle(), s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
		}
	}
	if (!s.songCount)
		throw ExSong(notSinger, songCount);
	return s;
}

int Songs::NumOfSongs()
{
	if (!songCount)
		return 0;
	return songCount;
}

void Songs::Remove(string tl)
{
	if (songCount == 0)
		throw ExSong(notSong, 0);
	Song* s = new Song[songCount];
	int i = 0;
	int k = 0;
	for (i = 0; i < songCount; i++)
	{
		if (song[i].GetTitle() != tl)
		{
			s[k].SetTitle(song[i].GetTitle());
			s[k].SetAuthor(song[i].GetAuthor());
			s[k].SetComposer(song[i].GetComposer());
			s[k].SetSinger(song[i].GetSinger());
			s[k].SetAlbumTitle(song[i].GetAlbumTitle());
			s[k].SetDay(song[i].GetDay());
			s[k].SetMonth(song[i].GetMonth());
			s[k].SetYear(song[i].GetYear());
			k++;
		}
	}
	songCount--;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
	{
		Assignment(i, s[i].GetTitle(), s[i].GetAuthor(), s[i].GetComposer(), s[i].GetSinger(), s[i].GetAlbumTitle(), s[i].GetDay(), s[i].GetMonth(), s[i].GetYear());
	}
	delete[] s;

	if (i == songCount)
		throw ExSong(notSong, 0);
}

Songs& Songs::operator=(const Songs& s)
{
	songCount = s.songCount;
	bufCount = s.bufCount;
	song = new Song[bufCount];
	for (int i = 0; i < songCount; i++)
	{
		Assignment(i, s.song[i].GetTitle(),
			s.song[i].GetAuthor(),
			s.song[i].GetComposer(),
			s.song[i].GetSinger(),
			s.song[i].GetAlbumTitle(),
			s.song[i].GetDay(), s.song[i].GetMonth(), s.song[i].GetYear());
	}
	return *this;
}

ostream& operator <<(ostream& stream, const Song& s)
{
	stream << s.GetTitle() << " " << s.GetAuthor() << " " << s.GetComposer() << " " << s.GetSinger() << " " << s.GetAlbumTitle() << " " << s.GetDay() << " " << s.GetMonth() << ' ' << s.GetYear();
	return stream;
}

istream& operator >>(istream& stream, Song& s)
{
	string tl, auth, com, sing, albt;
	int d, m, y;
	stream >> tl >> auth >> com >> sing >> albt >> d >> m >> y;
	s.SetTitle(tl);
	s.SetAuthor(auth);
	s.SetComposer(com);
	s.SetSinger(sing);
	s.SetAlbumTitle(albt);
	s.SetDay(d);
	s.SetMonth(m);
	s.SetYear(y);
	return stream;
}

