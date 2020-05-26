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

MediaPlayer::MediaPlayer() 
{
	size = 0;
	arr = new Song[size];
}

MediaPlayer::MediaPlayer(const Song _song) 
{
	size = 1;
	arr = new Song[size];
	arr[0] = _song;
}


void Song::SongInfo() 
{
	cout << "Name of song: " << Get_Sname() << endl;
	cout << "Author of song: " << Get_Author() << endl;
	cout << "Author of music: " << Get_Composer() << endl;
	cout << "Name of singer: " << Get_Singer() << endl;
	cout << "Name of album: " << Get_Album() << endl;
	cout << "Date of release: " << Get_Date() << endl << endl;;
}

void MediaPlayer::Add(string a, string b, string c, string d, string e, string f)
{
	if (size == 0) {
		size = 1;
		arr = new Song[size];
		arr[0] = Song(a, b, c, d, e, f);
		return;
	}
	size += 1;
	Song* tmp;
	tmp = new Song[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = new Song[size];
	for (int i = 0; i < size - 1; ++i) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
	arr[size - 1] = Song(a, b, c, d, e, f);

	for (int i = 0; i < size - 1; ++i) {
		for (int j = (size - 1); j > i; --j) {
			if (arr[j - 1].Get_Sname() > arr[j].Get_Sname()) {
				Song temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
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

int MediaPlayer::index_of_Song_name(string a) 
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Sname() == a) {
			return i;
		}
	}
	cout << "Song wasnt found" << endl << endl;
	return -1;
}

int MediaPlayer::index_of_Song_name_and_singer(string a, string b) 
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Sname() == a && arr[i].Get_Singer() == b) {
			cout << "Song was found" << endl;
			return i;
		}
	}
	cout << "Song wasnt found" << endl << endl;;
	return -1;
}

void MediaPlayer::AuthorSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Author() == a) arr[i].SongInfo();
	}
}

void MediaPlayer::ComposerSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Author() == a) arr[i].SongInfo();
	}
}

void MediaPlayer::SingerSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Singer() == a) arr[i].SongInfo();
	}
}

void MediaPlayer::Delete(int index) 
{
	Song* tmp;
	for (int i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	tmp = new Song[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	size--;

	arr = new Song[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = tmp[i];
	}
	delete[]tmp;
	cout << "Song deleted" << endl << endl;
}

void MediaPlayer::Load() 
{
	ofstream file;
	file.open("SongLib.txt");
	if (!file.is_open()) cout << "Cant open file" << endl;
	for (int i = 0; i < size; ++i) {
		file << "Name of song: " << arr[i].Get_Sname() << endl;
		file << "Author of song: " << arr[i].Get_Author() << endl;
		file << "Author of music: " << arr[i].Get_Composer() << endl;
		file << "Name of singer: " << arr[i].Get_Singer() << endl;
		file << "Name of album: " << arr[i].Get_Album() << endl;
		file << "Date of release: " << arr[i].Get_Date() << endl;
		file << endl;
		file.flush();
	}
	cout << "The data is recorded!" << endl;
	file.close();
}

void MediaPlayer::Read()
{
	MediaPlayer mass;
	ifstream fout;
	string _sname, _author, _composer, _singer, _album, _date, str;
	fout.open("ToRead.txt", ios::in);
	int tmp = 0;
	if (!fout.is_open()) cout << "Cant open file" << endl;
	while (getline(fout, str))
	{
		tmp++;
		if (tmp == 1) {
			_sname = str;
		}
		if (tmp == 2) {
			_author = str;
		}
		if (tmp == 3) {
			_composer = str;
		}
		if (tmp == 4) {
			_singer = str;
		}
		if (tmp == 5) {
			_album = str;
		}
		if (tmp == 6) {
			_date = str;
		}
		if (tmp == 6) {
			this->Add(_sname, _author, _composer, _singer, _album, _date);
			tmp = 0;
		}
	}
	fout.close();
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