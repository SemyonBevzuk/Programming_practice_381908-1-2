#include"Songs.h"

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

MediaPlayer::MediaPlayer(const MediaPlayer& player)
{
	size = player.size;
	arr = new Song[size];
	for (int i = 0; i < size; i++)
		arr[i] = player.arr[i];
}

MediaPlayer::~MediaPlayer()
{
	if(arr!=nullptr)
		delete[] arr;
	size = 0;
}

void MediaPlayer::Add(string _sname, string _author, string _composer, string _singer, string _album, string _date)
{
	if (size == 0) {
		size = 1;
		arr = new Song[size];
		arr[0] = Song(_sname, _author, _composer, _singer, _album, _date);
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
	arr[size - 1] = Song(_sname, _author, _composer, _singer, _album, _date);

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

int MediaPlayer::index_of_Song_name(string a) 
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i].Get_Sname() == a)
			return i;
	}
	cout << "Song wasnt found" << endl << endl;
	return -1;
}

int MediaPlayer::index_of_Song_name_and_singer(string _sname, string _singer) 
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Sname() == _sname && arr[i].Get_Singer() == _singer) 
		{
			cout << "Song was found" << endl;
			return i;
		}
	}
	cout << "Song wasnt found" << endl << endl;;
	return -1;
}

void MediaPlayer::ChangeSongInfo(int a, string _author, string _composer, string _singer, string _album, string _date)
{
	if (a != -1)
	{
		arr[a].Set_Author(_author);
		arr[a].Set_Composer(_composer);
		arr[a].Set_Singer(_singer);
		arr[a].Set_Album(_album);
		arr[a].Set_Date(_date);
	}
}

void MediaPlayer::AuthorSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Author() == a) PrintSongInfo(i);
	}
}

void MediaPlayer::ComposerSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Author() == a) PrintSongInfo(i);
	}
}

void MediaPlayer::SingerSongs(string a)
{
	for (int i = 0; i < size; ++i) {
		if (arr[i].Get_Singer() == a) PrintSongInfo(i);
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

int MediaPlayer::NumberOfSongs()
{
	return size;
}

void MediaPlayer::PrintSongInfo(int index)
{
	cout << "Name of song: " << arr[index].Get_Sname() << endl;
	cout << "Author of song: " << arr[index].Get_Author() << endl;
	cout << "Author of music: " << arr[index].Get_Composer() << endl;
	cout << "Name of singer: " << arr[index].Get_Singer() << endl;
	cout << "Name of album: " << arr[index].Get_Album() << endl;
	cout << "Date of release: " << arr[index].Get_Date() << endl << endl;;

}