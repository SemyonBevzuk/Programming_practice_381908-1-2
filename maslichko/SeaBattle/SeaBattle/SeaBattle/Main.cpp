#include "Game.h"
using namespace std;

int main()
{
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //� ����� ������

	int i1, i2, i3, i4, j1, j2, j3, j4; //��� ����� ��������� �������� ������
	int ctrl_user = 0, ctrl_pc = 0, ctrl_temp = 0; //�������� ����
	int mass[40] = { 0,0, 0,4, 0,8, 4,0, 2,2, 3,2, 2,8, 3,8, 4,5, 4,6, 6,1, 6,2, 6,3, 6,6, 7,6, 8,6, 9,0, 9,1, 9,2, 9,3 }; //���������� �������� ����������

	CreateField cf_pc(mass); //����������� �������� ����������
	CreateField cf_user;
	
	system("cls"); //������� �������
	
	//����������� �������� ������
	for (int q = 0; q < 4; q++)
	{
		cout << "������� ���������� ������������� �������: ";
		cin >> i1 >> j1;
		cf_user.Vessel(i1, j1);
	}

	for (int q = 0; q < 3; q++)
	{
		cout << "������� ���������� ������������� �������: ";
		cin >> i1 >> j1 >> i2 >> j2;
		cf_user.Vessel(i1, j1, i2, j2);
	}

	for (int q = 0; q < 2; q++)
	{
		cout << "������� ���������� ������������� �������: ";
		cin >> i1 >> j1 >> i2 >> j2 >> i3 >> j3;
		cf_user.Vessel(i1, j1, i2, j2, i3, j3);
	}

	cout << "������� ���������� ���������������� �������: ";
	cin >> i1 >> j1 >> i2 >> j2 >> i3 >> j3 >> i4 >> j4;
	cf_user.Vessel(i1, j1, i2, j2, i3, j3, i4, j4);

	Game game(cf_user, cf_pc);
	system("cls"); //������� �������
	while (ctrl_user != 20 || ctrl_pc != 20) //���� �� ����� 20(����� ���� ������ ��������) ��������� � ����-���� �� ������
	{
		if (ctrl_user == 20)
		{
			system("cls"); //������� �������
			cout << "�� ��������";
			return 0;
		}
		else if (ctrl_pc == 20)
		{
			system("cls"); //������� �������
			cout << "������� ���������";
			return 0;
		}

		Sleep(500);
		system("cls"); //������� �������
		game.Print();

		if (ctrl_user == ctrl_temp)
		{
			cout << endl << "���: ";
			cin >> i1 >> j1;
			int t = game.Step_user(i1, j1);
			if (t == 1)
			{
				cout << endl << "���������";
				ctrl_user++;
				ctrl_temp = ctrl_user; //������������ ��� ���������� ����

			}
			else if (t == 0)
			{
				cout << endl << "������";
				ctrl_temp = -1; //������ �������� ��� ���� ���������
			}
		}
		else
		{
			int t = game.Step_pc();
			if (t == 1)
			{
				ctrl_pc++;
				ctrl_temp = -1;
				cout << endl << "���������";
			}
			else if (t == 0)
			{
				ctrl_temp = ctrl_user;
				cout << endl << "������";
			}
		}
	}
	return 0;
}