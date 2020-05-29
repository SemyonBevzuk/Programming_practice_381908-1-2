#pragma once
#include "ProcCenter.h"
//libs there
using namespace std;

int sums[] = {100000, 500000, 1000000, 3000000};
int CountPercent(int srok, int summ);
int CountPayment(int sum, int srok, int percent);

class Credit {

private:
	string log;
	string pass;
	int wrongpass;
	int acc = 0;

public:
	Credit() {}
	~Credit() {}

	friend class ProcCenter;
	friend class Pers;

	void Search(ProcCenter &d); //search for account in base
	
	void GetCredit(ProcCenter &c); //new credit

	void AccInfo(ProcCenter &c);

	void CreditExist(ProcCenter &c); //check nalichie credita
	void CreditAbility(ProcCenter &c); //check ability to take new credit
	bool Check(ProcCenter &c, size_t credit); //calculation

	void GoToMenu(ProcCenter &c);

	void SignInOrUp(ProcCenter &c); //sign in or sign up
	void SignUp(ProcCenter &c); //sign up
	void Blocked(ProcCenter &c); //block card

	void PayPerMonth(ProcCenter &c); //monthly payment
	void DeleteCredit(ProcCenter &c); //pay off the entire sum
};