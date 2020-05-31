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
	void AllByPoet(string poet) const;
	void AllByComposer(string composer) const;
	void AllBySinger(string singer) const;
	int Number() const;
	void Delete(string title);
};

