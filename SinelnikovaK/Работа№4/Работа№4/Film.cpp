#include "Film.h"
using namespace std;

// �� ���������
Film::Film()
{
	name = "";
	producer = "";
	screenwriter = "";
	composer = "";
	day = mount = year = 0;
	fundraising = 0;
}

// �����������
Film::Film(const Film& film)
{
	*this = film;
}

// ����������
Film::~Film()
{
	name = "";
	producer = "";
	screenwriter = "";
	composer = "";
	day = mount = year = 0;
	fundraising = 0;
}

// ������������
Film& Film::operator=(const Film& film)
{
	name = film.name;
	producer = film.producer;
	screenwriter = film.screenwriter;
	composer = film.composer;
	day = film.day;
	mount = film.mount;
	year = film.year;
	fundraising = film.fundraising;
	return *this;
}

// ���������� ���������� � ������
void Film::UpdateFilm(const string _name, const string _producer, const string _screenwriter,
	const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising)
{
	name = _name;
	producer = _producer;
	screenwriter = _screenwriter;
	composer = _composer;
	day = _day;
	mount = _mount;
	year = _year;
	fundraising = _fundraising;
}

// �������������
Film::Film(const string _name, const string _producer, const string _screenwriter,
	const string _composer, const int _day, const int _mount, const int _year, const ll _fundraising)
{
	this->UpdateFilm(_name, _producer, _screenwriter, _composer, _day, _mount, _year, _fundraising);
}

// ���������� ������
string readString(const string comment)
{
	string str;
	cout << comment << ": ";
	getline(cin, str);
	return str;
}

// ��������� �������� ���������� � ������ (���� ������ �� �����)
ll UpdateNumber(const ll num, const string comment)
{
	string str = readString(comment);
	if (str != "")
		return stoll(str);
	return num;
}

// ��������� ��������� ���������� � ������ (���� ������ �� �����)
string UpdateString(const string str, const string comment)
{
	string newStr = readString(comment);
	if (newStr != "")
		return newStr;
	return str;
}

// ���������� ���������� � ������ � �������
Film& Film::Read()
{
	name = UpdateString(name, "��������");
	producer = UpdateString(producer, "�������");
	screenwriter = UpdateString(screenwriter, "���������");
	composer = UpdateString(composer, "����������");
	day = (int)UpdateNumber(day, "���� ������");
	mount = (int)UpdateNumber(mount, "����� ������");
	year = (int)UpdateNumber(year, "��� ������");
	fundraising = UpdateNumber(fundraising, "�����");
	return *this;
}

// ����� ���������� � ������ � �������
bool Film::Write()
{
	if (name == "")
		return false;
	cout << "��������:    " << name << "\n��������:    " << producer
		<< "\n���������:   " << screenwriter << "\n����������:  " << composer
		<< "\n���� ������: " << day << "." << mount << "." << year
		<< "\n�����:       " << fundraising << "�.\n";
	return true;
}

bool Film::operator!=(const Film& film)
{
	if (name == film.name || producer == film.producer || screenwriter == film.screenwriter || composer == film.composer
		|| day == film.day || mount == film.mount || year == film.year || fundraising == film.fundraising) return false;
	return true;
}

// swap �������
void swap(Film& f1, Film& f2)
{
	Film tmp = f1;
	f1 = f2;
	f2 = tmp;
}

// ���������� ���������� � ������ � �����
istream& operator>> (istream& stream, Film& film)
{
	getline(stream, film.name);
	getline(stream, film.producer);
	getline(stream, film.screenwriter);
	getline(stream, film.composer);
	stream >> film.day >> film.mount >> film.year >> film.fundraising;
	return stream;
}

// ����� ���������� � ������ � ����
ostream& operator<< (ostream& stream, const Film& film)
{
	stream << film.name << endl << film.producer
		<< endl << film.screenwriter << endl << film.composer
		<< endl << film.day << ' ' << film.mount << ' ' << film.year
		<< ' ' << film.fundraising << endl;
	return stream;
}
