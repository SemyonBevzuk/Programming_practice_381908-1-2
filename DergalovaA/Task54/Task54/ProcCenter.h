#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

class Pers {
private:
	string fname; //first
	string lname; //last
	string mname; //middle
	size_t money;

	string login;
	string password;

	bool CreditOn;
	int cred; //sum
	int plata; //payment
	int mm; //months
	int percent;

public:
	friend class Credit;
	friend class ProcCenter;
};

class ProcCenter {
private:
	Pers* pers; //array with persons
	int n; //kvo

public:
	friend class Credit;
	friend class Pers;
	ProcCenter();

	void AddPers();
	string SetPers(string _fname, string _lname, string _mname, string _pass, size_t _money);
	
	void SetCredit(int account, int payment, int summ, int mm, int percent);

};