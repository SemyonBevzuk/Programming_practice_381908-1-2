#include <iostream>
#include <clocale>
#include "Songs.h"
#include <fstream>

int main()
{
	setlocale(LC_ALL, "rus");
	string t = ""; //title
	string a = ""; //author
	string c = ""; //composer
	string sr = ""; //singer
	string al = ""; //album
	int d = 0, m = 0, y = 0;

	string txt = "Songs.txt";
	int exit = 0;
	Songs s;
	while (!exit)
	{
		try
		{
			cout << "�������� ��������:" << endl;
			cout << "1  - �������� �����" << endl;
			cout << "2  - �������� ������ �����" << endl;
			cout << "3  - ������ �� �������� � �����������" << endl;
			cout << "4  - ��� ����� ������ ������" << endl;
			cout << "5  - ��� ����� ������� �����������" << endl;
			cout << "6  - ��� ����� ������ �����������" << endl;
			cout << "7  - ���������� �����" << endl;
			cout << "8  - ������� �����" << endl;
			cout << "9  - ��������� ���������" << endl;
			cout << "10 - ������� ���������" << endl;
			cout << "0  - �����" << endl;
			int num;
			cin >> num;

			switch (num)
			{
			case(0):
			{
				exit = 1;
				break;
			}
			case(1):
			{
				cout << endl << "���������� �����: " << endl;
				cout << "�������� �����: ";   cin >> t;
				cout << "����� ������: ";     cin >> a;
				cout << "����������: ";       cin >> c;
				cout << "�����������: ";      cin >> sr;
				cout << "�������� �������: "; cin >> al;
				cout << "���� ������� ����� ������: ";     cin >> d >> m >> y;
				s.Add(t, a, c, sr, al, d, m, y);
				system("cls");
				cout << "����� ���������" << endl;
				break;
			}
			case(2):
			{
				cout << endl << "��������� ������ �����:" << endl;
				string str = "";
				cout << "�������� �����: ";	  cin >> str;
				cout << "����� �������� �����: ";   cin >> t;
				cout << "����� ������: ";     cin >> a;
				cout << "����������: ";       cin >> c;
				cout << "�����������: ";      cin >> sr;
				cout << "�������� �������: "; cin >> al;
				cout << "���� ������� ����� ������: ";     cin >> d >> m >> y;
				s.Edit(str, t, a, c, sr, al, d, m, y);
				system("cls");
				cout << "������ ����� ��������" << endl;
				break;
			}
			case(3):
			{
				cout << endl << "����� ����� �� �������� � �����������" << endl;
				cout << "�������� �����: ";	  cin >> t;
				cout << "�����������: ";      cin >> sr;
				system("cls");
				cout << "���� �����: ";
				Songs ss;
				ss = s.Search(t, sr);
				ss.Save("ppp.txt");


				break;
			}
			case(4):
			{
				cout << endl << "����� ���� ����� ��������� ������" << endl;
				cout << "����� ������: ";     cin >> a;
				system("cls");
				cout << "��� ������ ��������� ������:\n";
				s.AllSongAuthor(a).Save("ppp.txt");
				break;
			}
			case(5):
			{
				cout << endl << "����� ���� ����� ��������� ����������" << endl;
				cout << "����������: ";     cin >> a;
				system("cls");
				cout << "��� ������ ��������� �����������:" << endl;
				s.AllSongComposer(a).Save("ppp.txt");
				break;
			}
			case(6):
			{
				cout << endl << "����� ���� ����� ��������� �����������" << endl;
				cout << "�����������: ";     cin >> a;
				system("cls");
				cout << "��� ������ ��������� ����������:\n";
				Songs ss;
				ss = s.AllSongSinger(a);
				ss.Save("ppp.txt");
				break;
			}
			case(7):
			{
				system("cls");
				cout << endl << "����� �����: ";
				cout << s.NumOfSongs();
				cout << endl;
				break;
			}
			case(8):
			{
				cout << endl << "������� ����� �� �������� " << endl;
				cout << "�������� �����: ";	  cin >> t;
				s.Remove(t);
				system("cls");
				cout << "����� �������";
				cout << endl;
				break;
			}
			case(9):
			{
				s.Save(txt);
				system("cls");
				cout << "�������� �������" << endl;
			}
			case(10):
			{
				s.Open(txt);
			}
			default:
			{
				system("cls");
				break;
			}
			}
		}
		catch (ExSong ex)
		{
			switch (ex.type)
			{
			case(notSong):
			{
				system("cls");
				cout << "����� ����� ���" << endl;
				break;
			}
			case(notAuthor):
			{
				system("cls");
				cout << "������ ������ ���" << endl;
				break;
			}
			case(notComposer):
			{
				system("cls");
				cout << "������ ����������� ���" << endl;
				break;
			}
			case(notSinger):
			{
				system("cls");
				cout << "������ ����������� ���" << endl;
				break;
			}
			case(outOfArr):
			{
				system("cls");
				cout << "����� �� ������� �������" << endl;
			}
			default:
				break;
			}
		}
	}
	return 0;
}