#include"Bankomat.h"

int main()
{
	Bankomat atm;
	string s;
	int choice, id;
	bool ok = false, cardtaken = false, work = false;

	ProcCenter p1("1000", "1077", "Smith", 100),
		p2("1234", "7890", "Ivanov", 300),
		p3("1515", "9090", "Petrov", 25000);
	atm[0] = p1;
	atm[1] = p2;
	atm[2] = p3;

	do {
		do {
			system("cls");
			cout << "The Bank" << endl;
			s = atm.TakeCard();
			id = atm.FindClient(s, 3);
			if (id == -1)
			{
				atm.ReturnCard(s);
				system("pause");
			}
		} while (id == -1);
		atm.ShowStatus(s, 3);
		do {
			do {
				cout << "Choose an option:" << endl << "1 - Deposit cash\n2 - Cash withdraw\nPress any key to come back" << endl;
				cin >> choice;
			} while (choice > 1 && choice < 2);
			switch (choice)
			{
			case 1:
				atm.AddMoney(id);
				break;
			case 2:
				atm.MinusMoney(id);
				break;
			default:
				break;
			}
			do {
				cout << "Your actions: " << endl << "1 - Continue\n2 - Exit" << endl;
				cin >> choice;
			} while (choice > 1 && choice < 2);
			switch (choice)
			{
			case 1:
				cardtaken = false;
				break;
			case 2:
				cardtaken = atm.ReturnCard(s);
				work = true;
				break;
			default:
				break;
			}
		} while (cardtaken == false);
	} while (work == true);
}