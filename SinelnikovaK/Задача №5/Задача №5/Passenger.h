#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
class Passenger
{
	string surname;    // �������
	string name;       // ���
	string patronymic; // ��������
	string date;       // ���� �����������
	string depTime;    // ����� �����������
	string arrTime;    // ����� ��������
	int train;         // ����� ������
	int carriage;      // ����� ������
	int typeCar;       // ��� ������
	int seat;          // �����
	string departure;  // ������� �����������
	string arrival;    // ������� ��������

public:
	Passenger(const string surname = "", const string name = "", const string patronymic = "");
	Passenger(const Passenger& passenger);

	Passenger& operator= (const Passenger& passenger);
	bool operator== (const Passenger& passenger);
	void newSeatInfo(const int train, const string depTime, const string arrTime, const int carriage, const int typeCar,
		const int seat, const string departure, const string arrival, const string date);

	// ����-����� �������
	friend istream& operator>> (istream& stream, Passenger& passenger);
	friend ostream& operator<< (ostream& stream, const Passenger& passenger);
};
