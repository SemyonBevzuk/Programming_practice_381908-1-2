#pragma once
#include<string>
#include"ProcCenter.h"

class Bankomat
{
private:
	ProcCenter* person;
	unsigned int c100;
	unsigned int c200;
	unsigned int c500;
	unsigned int c1000;
	unsigned int c2000;
	unsigned int c5000;
	unsigned int num_of_clients;
public:
	Bankomat();
	~Bankomat();

	string TakeCard();
	int FindClient(string s, int list);
	bool PINCheck(int id);
	bool ShowStatus(string s, int list);
	void AddMoney(int id);
	void MinusMoney(int id);

	bool ReturnCard(string s);

	bool Set100(unsigned int m);
	bool Set200(unsigned int m);
	bool Set500(unsigned int m);
	bool Set1000(unsigned int m);
	bool Set2000(unsigned int m);
	bool Set5000(unsigned int m);

	unsigned int Get100();
	unsigned int Get200();
	unsigned int Get500();
	unsigned int Get1000();
	unsigned int Get2000();
	unsigned int Get5000();

	ProcCenter& operator[](const int proc);
};