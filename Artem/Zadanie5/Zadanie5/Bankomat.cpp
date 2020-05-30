#include"Bankomat.h"

Bankomat::Bankomat()
{
	ProcCenter proc;
	num_of_clients = 4;
	person = new ProcCenter[num_of_clients];

	this->c100 = 1600;
	this->c200 = 1600;
	this->c500 = 1600;
	this->c1000 = 1600;
	this->c2000 = 1600;
	this->c5000 = 1600;
	for (int i = 0; i < (int)num_of_clients; i++)
		person[i] = proc;
}

Bankomat::~Bankomat()
{
	ProcCenter proc;
	num_of_clients = 4;
	this->c100 = 1600;
	this->c200 = 1600;
	this->c500 = 1600;
	this->c1000 = 1600;
	this->c2000 = 1600;
	this->c5000 = 1600;
	for (int i = 0; i < (int)num_of_clients; i++)
		person[i] = proc;
}

string Bankomat::TakeCard()
{
	int i = 0;
	int check, size;
	bool ok = false;
	string s;
	char* f;
	cout << "Enter ID of the card"<<endl;
	do {
		cin >> s;
		i++;
		size = s.length();
		f = new char[size];
		for (int i = 0; i < size; i++)
			f[i] = s[i];
		check = atoi(f);
		if (check != 0 && check > 0 && check <= 9999)
			return s;
		else
		{
			if (s == "0000")
				return s;
			cout << "Input Error!" << endl << "Attempts left: " << 3 - i << endl;
		}
	} while (i < 3);
	return s = "null";
}

int Bankomat::FindClient(string s, int list)
{
	string ss;
	int i;
	bool ret = false;
	for (i = 0; i < list; i++)
	{
		ss = person[i].GetCard();
		if (strcmp(ss.c_str(), s.c_str())==0)
			if (person[i].GetWrong() == true)
			{
				cout << "Your card is banned." << endl;
				system("pause");
				return -1;
			}
		ret = PINCheck(i);
		if (ret == true)
			return i;
		else return -1;
	}
	cout << "The card wasn't found" << endl;
	return -1;
}

bool Bankomat::PINCheck(int ID)
{
	int i = 0;
	int check, size;
	bool ok = false;
	string s;
	char* f;
	cout << "Enter PIN: ";
	do {
		cin >> s;
		i++;
		size = s.length();
		f = new char[size];
		for (int k = 0; k < size; k++)
			f[k] = s[k];
		check = atoi(f);
		if (check != 0 && s == person[ID].GetPassword())
			return true;
		else
		{
			if (s == "0000" && s == person[ID].GetPassword())
				return true;
			cout << "Wrong password" << endl << "Attempts left: " << 3 - i << endl;
		}
	} while (i < 3);
	cout << "The card is banned" << endl;
	person[ID].SetWrong(true);
	system("pause");
	return false;
}

bool Bankomat::ShowStatus(string s, int list)
{
	string ss;
	int i;
	bool ok = false;
	for (i = 0; i < list; i++)
	{
		ss = person[i].GetCard();
		if (strcmp(ss.c_str(), s.c_str()) == 0)
		{
			cout << "Wellcome, " << person[i].GetClient() << endl;
			cout << "Your balance: " << person[i].GetMoney() << endl;
			return true;
		}
	}
	cout << "The card wasn't found" << endl;
	return false;
}

void Bankomat::AddMoney(int id)
{
	unsigned int k100, k200, k500, k1000, k2000, k5000, cash;
	bool ok;
	cout << "Acepted banknotes: 100, 200, 500, 1000, 2000, 5000 rubles" << endl;
	do {
		cout << "Deposite cash" << endl;
		cout << "Number of notes at 100 rub - ";
		cin >> k100;
		cout << "Number of notes at 200 rub - ";
		cin >> k200;
		cout << "Number of notes at 500 rub - ";
		cin >> k500;
		cout << "Number of notes at 1000 rub - ";
		cin >> k1000;
		cout << "Number of notes at 2000 rub - ";
		cin >> k2000;
		cout << "Number of notes at 5000 rub - ";
		cin >> k5000;
		if (k100 + k200 + k500 + k1000 + k2000 + k5000 > 30)
			cout << endl << "ATM takes only 30 bills at a time." << endl;
	} while (k100 + k200 + k500 + k1000 + k2000 + k5000 > 30);
	ok = Set100(c100 += k100);
	ok = Set200(c200 += k200);
	ok = Set500(c500 += k500);
	ok = Set1000(c1000 += k1000);
	ok = Set2000(c2000 += k2000);
	ok = Set5000(c5000 += k5000);
	if (ok == false)
	{
		cash = k100 * 100 + k200 * 200 + k500 * 500 + k1000 * 1000 + k2000 * 2000 + k5000 * 5000;
		cout << endl << "Completed!" << endl;
		person[id].SetMoney(person[id].GetMoney() + cash);
		cout << "Entered on your card: " << cash << " rub" << endl << endl;
		cout << "Your balance: " << person[id].GetMoney() << endl << endl;
	}
	else
		cout << "Operation failed!" << endl << endl;
}

void Bankomat::MinusMoney(int id)
{
	unsigned int k100, k200, k500, k1000, k2000, k5000, cash;
	bool ok;
	cout << "The amount of monay you would like to withdraw" << endl;
	do {
		cout << "Deposite cash" << endl;
		cout << "Number of notes at 100 rub - ";
		cin >> k100;
		cout << "Number of notes at 200ð rub - ";
		cin >> k200;
		cout << "Number of notes at 500ð rub - ";
		cin >> k500;
		cout << "Number of notes at 1000ð rub - ";
		cin >> k1000;
		cout << "Number of notes at 2000ð rub - ";
		cin >> k2000;
		cout << "Number of notes at 5000ð rub - ";
		cin >> k5000;
		if (k100 + k200 + k500 + k1000 + k2000 + k5000 > 30)
			cout << endl << "ATM takes only 30 bills at a time." << endl;
	} while (k100 + k200 + k500 + k1000 + k2000 + k5000 > 30);

	ok = Set100(c100 -= k100);
	ok = Set200(c200 -= k200);
	ok = Set500(c500 -= k500);
	ok = Set1000(c1000 -= k1000);
	ok = Set2000(c2000 -= k2000);
	ok = Set5000(c5000 -= k5000);

	cash = k100 * 100 + k200 * 200 + k500 * 500 + k1000 * 1000 + k2000 * 2000 + k5000 * 5000;
	if (person[id].GetMoney()<cash)
	{
		cout << "There is not enough money in the account." << endl;
		ok = true;
	}
	if (ok == false)
	{
		cout << endl << "Completed!" << endl;
		person[id].SetMoney(person[id].GetMoney() - cash);
		cout << "Money withdrawn: " << cash << " rub" << endl << endl;
		cout << "Your balance: " << person[id].GetMoney() << endl << endl;
	}
	else
		cout << "Operation failed!" << endl << endl;
}

bool Bankomat::ReturnCard(string s)
{
	cout << "The card " << s << " was returned." << endl << endl;
	return true;
}

bool Bankomat::Set100(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c100 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 100 rub or empty" << endl;
		return 1;
	}
}

bool Bankomat::Set200(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c200 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 200 rub or empty" << endl;
		return 1;
	}
}

bool Bankomat::Set500(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c500 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 500 rub or empty" << endl;
		return 1;
	}
}

bool Bankomat::Set1000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c1000 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 1000 rub or empty" << endl;
		return 1;
	}
}

bool Bankomat::Set2000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c2000 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 2000 rub or empty" << endl;
		return 1;
	}
}

bool Bankomat::Set5000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c5000 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 5000 rub or empty" << endl;
		return 1;
	}
}

unsigned int Bankomat::Get100()
{
	return this->c100;
}

unsigned int Bankomat::Get200()
{
	return this->c200;
}

unsigned int Bankomat::Get500()
{
	return this->c500;
}

unsigned int Bankomat::Get1000()
{
	return this->c1000;
}

unsigned int Bankomat::Get2000()
{
	return this->c2000;
}

unsigned int Bankomat::Get5000()
{
	return this->c5000;
}

ProcCenter& Bankomat::operator[](const int id)
{
	return this->person[id];
}