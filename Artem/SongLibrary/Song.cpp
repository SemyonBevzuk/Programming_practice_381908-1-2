#include"Songs.h"

Song::Song(string _sname, string _author, string _composer, string _singer, string _album, string _date)
{
	sname = _sname;
	author = _author;
	composer = _composer;
	singer = _singer;
	album = _album;
	date = _date;
}

void Song::Set_Sname(string _sname)
{
	sname = _sname;
}

void Song::Set_Composer(string _composer)
{
	composer = _composer;
}

void Song::Set_Singer(string _singer)
{
	singer = _singer;
}

void Song::Set_Album(string _album)
{
	album = _album;
}

void Song::Set_Date(string _date)
{
	date = _date;
}

void Song::Set_Author(string _author)
{
	author = _author;
}

bool operator==(const Song& left, const Song& right)
{
	if (left.Get_Composer() == right.Get_Composer() &&
		left.Get_Author() == right.Get_Author() &&
		left.Get_Date() == right.Get_Date() &&
		left.Get_Album() == right.Get_Album() &&
		left.Get_Singer() == right.Get_Singer() &&
		left.Get_Sname() == right.Get_Sname()) {
		return 1;
	}
	else return 0;
}