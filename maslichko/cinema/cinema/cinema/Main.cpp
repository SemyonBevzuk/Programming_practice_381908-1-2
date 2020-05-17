#include "TicketOffice.h"

int main()
{
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //� ����� ������
	vector<Cinema> film1; //������, ������ ������ � �������
	//��������� ������
	film1.push_back(Cinema(13, 05, 2020, 8, 00, "����� �� ��������", 1, 300));
	film1.push_back(Cinema(13, 05, 2020, 13, 15, "������ ������", 1, 300));
	film1.push_back(Cinema(13, 05, 2020, 18, 00, "���", 1, 300));

	film1.push_back(Cinema(16, 05, 2020, 8, 00, "����", 2, 400));
	film1.push_back(Cinema(16, 05, 2020, 12, 00, "������", 2, 400));
	film1.push_back(Cinema(16, 05, 2020, 18, 00, "������� ������", 2, 400));

	TicketOffice t1(film1); //�������� ������ � ����� �����
	Date w1(13, 5, 2020, 13, 20); //������������� ����

	int menu, t;
	int day, month;
	int quantity;
	vector<string> temp, temp_ticket;
	string name_temp, zone;

	while (1)
	{
		cout << endl;
		cout << "1. ������ ������" << endl;
		cout << "2. ������ ������" << endl;
		cout << "3. ������ ������� ����" << endl;
		cout << "4. ��������������� �����" << endl;
		cout << "5. �������� ������� �������" << endl;
		cout << "6. ������������ ������" << endl;
		cout << endl << "�������� ��������: ";

		cin >> menu;

		switch (menu)
		{
		case 1:
			temp = t1.Print(); //����� ���� �������
			for (int i = 0; i < temp.size(); i++)
			{
				cout << endl << temp[i] << endl;
			}
			break;
		case 2:
			cout << endl << "������� ����(���� �����):";
			cin >> day >> month;
			cin.get();
			cout << endl << "������� �������� ������: ";
			getline(cin, name_temp);
			cout << endl << "������� ���������� �������: ";
			cin >> quantity;
			cout << endl << "������� ����: (base/vip): ";
			cin >> zone;

			t = t1.Buy(day, month, name_temp, quantity, zone, w1); //�������

			if (t == 0)
			{
				cout << endl << "���� ���, ���� ���� ������� ����� ��� ��� �� ��������.";
			}
			else if (t != 0)
			{
				cout << endl << "������ ��������, � ������ - " << t;
			}
			break;
		case 3:
			cout << endl << "������� ����(���� �����):";
			cin >> day >> month;
			cin.get();
			cout << endl << "������� �������� ������: ";
			getline(cin, name_temp);

			t = t1.FindPlaces(day, month, name_temp); //��������� �����
			cout << endl << "���� ��������: " << t;
			break;
		case 4:
			cout << endl << "������� ����(���� �����):";
			cin >> day >> month;
			cin.get();
			cout << endl << "������� �������� ������: ";
			getline(cin, name_temp);
			cout << endl << "������� ���������� �������: ";
			cin >> quantity;
			cout << endl << "������� ����: (base/vip): ";
			cin >> zone;

			t = t1.Reservation(day, month, name_temp, quantity, zone); //������

			if (t == 0)
			{
				cout << endl << "���� ���.";
			}
			else if (t == 1)
			{
				cout << endl << "������ �������������.";
			}
			break;
		case 5:
			cout << endl << "������� ����(���� �����):";
			cin >> day >> month;
			cin.get();
			cout << endl << "������� �������� ������: ";
			getline(cin, name_temp);
			cout << endl << "������� ���������� ������� ��� ������: ";
			cin >> quantity;

			t = t1.Cancel(day, month, name_temp, quantity); //������
			if (t == 0)
			{
				cout << endl << "������� �������� ���� ���.";
			}
			else if (t == 1)
			{
				cout << endl << "������� ��������.";
			}

			break;
		case 6:
			cout << endl << "������� ����(���� �����):";
			cin >> day >> month;
			cin.get();
			cout << endl << "������� �������� ������: ";
			getline(cin, name_temp);

			temp_ticket = t1.CreateTicket(day, month, name_temp); //������������
			for (int i = 0; i < temp_ticket.size(); i++)
			{
				cout << endl << temp_ticket[i];
			}
			break;
		}
	}
	return 0;
}