#include "Credit.h"

int CountPercent(int srok, int summ)
{
	int percent;
	switch (srok) //years
	{
	case 1:
		if (summ < sums[0])
			percent = 16;
		else
			if (summ < sums[1])
				percent = 15;
			else
				if (summ < sums[2])
					percent = 13;
				else
					percent = 12;
		break;
	case 2:
		if (summ < sums[0])
			percent = 15;
		else
			if (summ < sums[1])
				percent = 14;
			else
				if (summ < sums[2])
					percent = 13;
				else
					percent = 12;
		break;
	case 3:
		if (summ < sums[0])
			percent = 14;
		else
			if (summ < sums[1])
				percent = 13;
			else
				if (summ < sums[2])
					percent = 12;
				else
					percent = 10;
		break;
	case 5:
		if (summ < sums[0])
			percent = 12;
		else
			if (summ < sums[1])
				percent = 11;
			else
				if (summ < sums[2])
					percent = 10;
				else
					percent = 9;
		break;
	case 15:
		if (summ < sums[0])
			percent = 12;
		else
			if (summ < sums[1])
				percent = 10;
			else
				if (summ < sums[2])
					percent = 9;
				else
					percent = 8;
	}
	return percent;
}

int CountPayment(int sum, int srok, int percent) {
	double b = 1;
	double pc = (double)percent / 100.0;
	for (int i = 0; i < srok*12; i++)
	{ // pow (1 + percent/100, srok*12)
		b *= (1.0 + pc);
	}
	double X = (double)sum * b * pc / (b - 1.0);
	return (int)X;
}

void Credit::Search(ProcCenter & c) {
	//real login or not
	int i = 0;
	bool f = false, g = false;

	do {
		if (c.pers[i].login == log)
			f = true;
		else
			i++;
	} while (i < c.n && !f);

	if (f)
	{ //login exists
	  //i is number
		if (c.pers[i].password == pass) {
			acc = i;
			wrongpass = 0;
			g = true;
		}
		else
		{
			wrongpass++;
			if (wrongpass == 3)
				Blocked(c);
			else
				cout << "Wrong password" << endl;
		}
	}
	else
		cout << "User not found" << endl;

	if (f && g)
		GoToMenu(c);
	else
		SignInOrUp(c);
}

void Credit::PayPerMonth(ProcCenter &c) {
	if (!c.pers[acc].CreditOn) {
		cout << "No credit" << endl;
	}
	else {
		
		if (c.pers[acc].money - c.pers[acc].plata < 0) {
			cout << "You can't pay" << endl;
		}
		else {
			c.pers[acc].mm--;
			c.pers[acc].money -= c.pers[acc].plata;
			c.pers[acc].cred = int(c.pers[acc].cred * ( 1.0 + (double)c.pers[acc].percent / 100.0));
			c.pers[acc].cred -= c.pers[acc].plata;
			cout << "Payment accepted" << endl;

			if (c.pers[acc].mm == 0) {
				cout << "Credit is repaid!" << endl;
				c.pers[acc].CreditOn = false;
				c.pers[acc].plata = 0;
				c.pers[acc].cred = 0;
				c.pers[acc].percent = 0;
			}
		}
	}
	GoToMenu(c);
}

void Credit::DeleteCredit(ProcCenter &c) {
	if (!c.pers[acc].CreditOn) {
		cout << "No credit" << endl;
	}
	else {
		if (c.pers[acc].money < c.pers[acc].cred) {
			cout << "You can't pay" << endl;
		}
		else {
			c.pers[acc].money -= c.pers[acc].cred;
			c.pers[acc].CreditOn = false;
			c.pers[acc].mm = 0;
			c.pers[acc].plata = 0;
			c.pers[acc].cred = 0;
			c.pers[acc].percent = 0;
			cout << "Payment accepted" << endl;
			cout << "Credit is repaid!" << endl;
		}
	}
	GoToMenu(c);
}

void Credit::Blocked(ProcCenter &c) {
	wrongpass = 0;

	for (int i = 10; i > 0; i--) {
		system("cls");
		cout << "Your card is blocked for " << i << " sec" << endl;
		Sleep(1000);
	}
	SignInOrUp(c);
}

void Credit::SignUp(ProcCenter &c) {
	system("cls");
	cout << "Login: ";
	cin >> log;
	cout << "Password: ";
	cin >> pass;
	Search(c);
}

void Credit::SignInOrUp(ProcCenter &c) {
	system("cls");
	bool v;
	cout << "0 - Log in" << endl << "1 - Register" << endl;
	cin >> v;
	if (!v)
		SignUp(c);
	else
	{
		c.AddPers();
		acc = c.n - 1;
	}
	GoToMenu(c);
}

void Credit::AccInfo(ProcCenter &c) {
	cout << "User: " << c.pers[acc].login << " | " << c.pers[acc].fname << " " << c.pers[acc].lname << " " << c.pers[acc].mname << endl;
	cout << "Amount: " << c.pers[acc].money << endl;

	if (!c.pers[acc].CreditOn) {
		cout << endl << "No credit" << endl;
	}
	else {
		cout << endl << "Credit (roubles): " << c.pers[acc].cred << endl;
		cout << "Monthly payment (roubles): " << c.pers[acc].plata << endl;
		cout << "Remaining period (months): " << c.pers[acc].mm << endl;
	}
	GoToMenu(c);
}

bool Credit::Check(ProcCenter &c, size_t credit) {
	bool can = false;
	if ((credit * 6) < c.pers[acc].money)
		can = true;
	return can;
}

void Credit::GetCredit(ProcCenter &c) {
	if (c.pers[acc].CreditOn)
		cout << "You already have a credit" << endl;
	else
	{
		cout << "Password: ";
		cin >> pass;
		while (pass != c.pers[acc].password && wrongpass != 3)
		{
			wrongpass++;
			cout << "Wrong password, try again: ";
			cin >> pass;
		}
		if (wrongpass == 3)
			Blocked(c);
		else {
			int summ, v;
			do
			{
				cout << "Enter the amount (< 3 000 000): ";
				cin >> summ;
			} while (summ < 1 || summ > sums[3]);

			do {
				cout << "Choose a period: 1, 2, 3, 5 or 15 years (enter only a number): ";
				cin >> v;
			} while (v != 1 && v != 2 && v != 3 && v != 5 && v != 15);

			int pc = CountPercent(v, summ);
			int payment = CountPayment(summ, v, pc);

			if (c.pers[acc].money > payment*6)
			{
				cout << "Credit approved" << endl;
				c.SetCredit(acc, payment, summ, 12 * v, pc);
			}
			else cout << "Credit isn't approved" << endl;

		}
	}
	GoToMenu(c);
}

void Credit::CreditAbility(ProcCenter &c) {
	if (c.pers[acc].CreditOn == true) {
		cout << "You already have a credit" << endl;
	}
	else {
		int summ;
		
		do {
			cout << "Enter the amount (< 3 000 000): ";
			cin >> summ;
		} while (summ < 1 || summ > sums[3]);
		int v;
		cout << endl;
		do {
			cout << "Choose a period: 1, 2, 3, 5 or 15 years (enter only a number): ";
			cin >> v;
		} while (v != 1 && v != 2 && v != 3 && v != 5 && v != 15);
		int pc = CountPercent(v, summ);
		int payment = CountPayment(summ, v, pc);

		if (c.pers[acc].money > payment * 6)
			cout << "Credit would be approved" << endl;
		else cout << "Credit wouldn't be approved" << endl;
	}
	GoToMenu(c);
}

void Credit::CreditExist(ProcCenter &c) {
	if (c.pers[acc].CreditOn == false) {
		cout << "You can take new credit! Our percentage rates: " << endl;
		cout << "years |   %" << endl;
		cout << "  1   | 12-16" << endl;
		cout << "  2   | 12-15" << endl;
		cout << "  3   | 10-14" << endl;
		cout << "  5   | 9-12" << endl;
		cout << "  15  | 8-12" << endl;
	}
	else {
		cout << "You already have a credit" << endl;
	}
	GoToMenu(c);
}

void Credit::GoToMenu(ProcCenter &c) {

	cout << endl << "1 - Change account" << endl;
	cout << "2 - Account INFO" << endl;
	cout << "3 - Check for credits" << endl;
	cout << "4 - Check the ability to take new credit" << endl;
	cout << "5 - Get new credit" << endl;
	cout << "6 - Make a monthly payment" << endl;
	cout << "7 - Pay off the entire credit" << endl;
	cout << "8 - Exit" << endl;

	int v;
	do {
		cin >> v;
	} while (v < 1 || v > 8);
	system("cls");
	switch (v) {
	case 1: SignInOrUp(c); break;
	case 2: AccInfo(c); break;
	case 3: CreditExist(c); break;
	case 4: CreditAbility(c); break;
	case 5: GetCredit(c); break;
	case 6: PayPerMonth(c); break;
	case 7: DeleteCredit(c); break;
	case 8: exit(0); break;
	}
}
