#include "ProcCenter.h"

ProcCenter::ProcCenter()
{
	pers = nullptr;
	n = 0;
}

//registration
void ProcCenter::AddPers() {
	

	system("cls");
	string fname, lname, mname, password;
	int money;
	cout << endl;
	cout << "First name: ";
	cin >> fname;
	cout << "Last name: ";
	cin >> lname;
	cout << "Middle name: ";
	cin >> mname;
	cout << "Password: ";
	cin >> password;
	do
	{
		cout << "Amount: ";
		cin >> money;
	} while (money < 0);

	string l = SetPers(fname, lname, mname, password, money);

	cout << "Your login is " << l << endl;
}

//new pers
string ProcCenter::SetPers(string _fname, string _lname, string _mname, string _password, size_t _money) {
	n++;
	char login[5];
	if (n < 10) {
		login[0] = '0';
		login[1] = '0';
		login[2] = '0';
		login[3] = n + '0';
		login[4] = '\0';
	}
	else {
		if ((n >= 10) && (n < 100)) {
			int k = n % 10;
			int j = n / 10;
			login[0] = '0';
			login[1] = '0';
			login[2] = j + '0';
			login[3] = k + '0';
			login[4] = '\0';
		}
		else {
			if (n >= 100 && n < 1000) {
				int j2 = (n % 100) / 10;
				int j3 = n % 10;
				int j = n / 100;
				login[0] = '0';
				login[1] = j + '0';
				login[2] = j2 + '0';
				login[3] = j3 + '0';
				login[4] = '\0';
			}
			else {
				if (n >= 1000 && n < 10000) {
					int j = n / 1000;
					int j1 = (n / 100) % 10;
					int j2 = (n / 10) % 10;
					int j3 = n % 10;
					login[0] = j + '0';
					login[1] = j1 + '0';
					login[2] = j2 + '0';
					login[3] = j3 + '0';
					login[4] = '\0';
				}
				else {
					exit(0);
				}
			}
		}
	}

	Pers* buffer = nullptr;

	if (pers != nullptr)
	{
		Pers* buffer = new Pers[n];
		for (int i = 0; i < n - 1; i++)
		{
			buffer[i].fname = pers[i].fname;
			buffer[i].lname = pers[i].lname;
			buffer[i].mname = pers[i].mname;
			buffer[i].money = pers[i].money;
			buffer[i].login = pers[i].login;
			buffer[i].password = pers[i].password;
			buffer[i].CreditOn = pers[i].CreditOn;
			buffer[i].plata = pers[i].plata;
			buffer[i].mm = pers[i].mm;
		}
		delete[] pers;
		pers = new Pers[n];

		for (int i = 0; i < n - 1; i++)
		{ //n is empty
			pers[i].fname = buffer[i].fname;
			pers[i].lname = buffer[i].lname;
			pers[i].mname = buffer[i].mname;
			pers[i].money = buffer[i].money;
			pers[i].login = buffer[i].login;
			pers[i].password = buffer[i].password;
			pers[i].CreditOn = buffer[i].CreditOn;
			pers[i].plata = buffer[i].plata;
			pers[i].mm = buffer[i].mm;
		}
		delete[] buffer;
	}
	else
		pers = new Pers[n];
	
	int i = n - 1;

	pers[i].fname = _fname;
	pers[i].lname = _lname;
	pers[i].mname = _mname;
	pers[i].money = _money;

	pers[i].login = string(login);
	pers[i].password = _password;

	pers[i].CreditOn = false;
	pers[i].plata = 0;
	pers[i].mm = 0;

	return login;
}

void ProcCenter::SetCredit(int account, int payment, int summ, int mm, int percent) {
	pers[account].plata = payment;
	pers[account].mm = mm;
	pers[account].money += summ;
	pers[account].cred = summ;
	pers[account].percent = percent;
	pers[account].CreditOn = true;
}