#pragma once
#include "Song.h"
#include <vector>

class Songs
{
private:
	vector<Song> songs;
public:
	Songs();
	~Songs();
	friend ofstream& operator<<(ofstream& out, const Songs& S);
	friend ifstream& operator>>(ifstream& in, Songs& S);
	void AddSong(Song S);
	void ChangeSong(string title, char ch, string info = "", Date date = Date());
	Song FindSong(string title, string singer) const;
	vector<Song> AllByPoet(string poet) const;
	vector<Song> AllByComposer(string composer) const;
	vector<Song> AllBySinger(string singer) const;
	int GetSize() const;
	void Delete(string title);
};

