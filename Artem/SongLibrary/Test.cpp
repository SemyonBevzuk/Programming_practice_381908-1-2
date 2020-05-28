#include"Songs.h"

int main()
{
	int index;
	int number;
	string sname, author, composer, singer, album, date, str;
	MediaPlayer SongLibrary;
	ifstream file;
	int tmp = 0;

	while (1) {
		cout << "MediaPlayer:" << endl;
		cout << "1. Add song" << endl;
		cout << "2. Edit song data" << endl;
		cout << "3. Find a song by title and artist" << endl;
		cout << "4. Get all songs of the given author" << endl;
		cout << "5. Get all songs of the given composer" << endl;
		cout << "6. Get all songs of the given artist" << endl;
		cout << "7. Find out the current number of songs" << endl;
		cout << "8. Delete song" << endl;
		cout << "9. Read data from file" << endl;
		cout << "10. Write data to file" << endl;
		cout << "11. Exit the program" << endl;
		cin >> number;
		cin.ignore();
		cout << endl;
		switch (number) {
		case 1:
			system("cls");
			cout << "Name of song : ";
			getline(cin, sname);
			cout << "Author of song: ";
			getline(cin, author);
			cout << "Author of music: ";
			getline(cin, composer);
			cout << "Name of singer: ";
			getline(cin, singer);
			cout << "Name of album: ";
			getline(cin, album);
			cout << "Date of release: ";
			getline(cin, date);
			cout << endl;
			SongLibrary.Add(sname, author, composer, singer, album, date);
			break;
		case 2:
			system("cls");
			cout << "Enter the name of the song whose data you want to change: ";
			getline(cin, sname);
			cout << endl;
			index = SongLibrary.index_of_Song_name(sname);
			if (index == -1) break;
			cout << "Enter new data:" << endl;
			cout << "Author of song: ";
			getline(cin, author);
			cout << "Author of music: ";
			getline(cin, composer);
			cout << "Singer: ";
			getline(cin, singer);
			cout << "Name of song: ";
			getline(cin, album);
			cout << "Date of release: ";
			getline(cin, date);
			SongLibrary.ChangeSongInfo(index, author, composer, singer, album, date);
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "Enter the name of the song and name of singer you want to find" << endl;
			cout << "Name of song: ";
			getline(cin, sname);
			cout << "Name of singer: ";
			getline(cin, author);
			cout << endl;
			index = SongLibrary.index_of_Song_name_and_singer(sname, author);
			if (index == -1) break;
			cout << "About song: " << endl;
			if (index != -1) SongLibrary.PrintSongInfo(index);
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "Enter the name of author of songs whose songs you want to find: ";
			getline(cin, sname);
			SongLibrary.AuthorSongs(sname);
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "Enter the name of author of music whose songs you want to find: ";
			getline(cin, sname);
			SongLibrary.ComposerSongs(sname);
			cout << endl;
			break;
		case 6:
			system("cls");
			cout << "Enter the name of singer whose songs you want to find: ";
			getline(cin, sname);
			SongLibrary.SingerSongs(sname);
			cout << endl;
			break;
		case 7:
			system("cls");
			cout << SongLibrary.NumberOfSongs() << endl;
			break;
		case 8:
			system("cls");
			cout << "Enter the name of song whose you want to delete: ";
			getline(cin, sname);
			index = SongLibrary.index_of_Song_name(sname);
			if (index == -1) break;
			SongLibrary.Delete(index);
			cout << endl;
			break;
		case 9:
			system("cls");
			SongLibrary.Read();
			break;
		case 10:
			system("cls");
			SongLibrary.Load();
			break;
		case 11:
			exit(1);
		}
	}
	return 0;
}