#include "Game.h"
using namespace std;

void Ship(CreateField &cf_user)
{
	int i1, i2, i3, i4, j1, j2, j3, j4; //��� ����� ��������� �������� ������

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
}

int Game_process(Game game)
{
	int ctrl_user = 0, ctrl_pc = 0, ctrl_temp = 0; //�������� ����
	int i1, j1;
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
				cout << endl << "��������� � ������� ����������";
				ctrl_user++;
				ctrl_temp = ctrl_user; //������������ ��� ���������� ����

			}
			else if (t == 0)
			{
				cout << endl << "����� �����������";
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
				cout << endl << "��������� � ������� ������";
			}
			else if (t == 0)
			{
				ctrl_temp = ctrl_user;
				cout << endl << "��������� �����������";
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //� ����� ������
	int i1, j1;
	
	CreateField cf_pc("pc"); //����������� �������� ����������
	CreateField cf_user;
	
	system("cls"); //������� �������
	
	Ship(cf_user);

	Game game(cf_user, cf_pc); //�������� � ����� Game ������� ����
	system("cls"); //������� �������

	Game_process(game);
	
	return 0;
}