#include "Game.h"

void Game::Print()
{
	cout << field_user;
}

int Game::Step_user(int i, int j) //��� ������
{
	if (field_pc.field_main[i][j] == "X ") //���� �����
	{
		field_user.field_second[i][j] = "X "; //�� ����� ������ ����� ������� ���������
		field_pc.field_main[i][j] == "Z "; //�� ����� ��������� ������� ��������
		return 1;
	}
	else
	{
		field_user.field_second[i][j] = "M "; //���� ������, ������� ��� �� ����� ������ �����
		return 0;
	}
}

int Game::Step_pc() //��� ����������
{
	int i = 0, j = 0, q = 0;
	srand(time(NULL)); //����� ��������� ����� �� ������ ����������
	while (q == 0) //����������, ���� �� ����� �������� ����������, ������� ��� �� ��������������
	{
		i = rand() % 9; //�� 0 �� 9
		j = rand() % 9;
		if (field_pc.field_second[i][j] == "O ") //���� � ��� ����� ��� �� ���� ����, �� ������� �� �����
		{
			q = 1;
		}
		else //����� ���������� ����� ����������
		{
			i = rand() % 9;
			j = rand() % 9;
		}
	}

	if (field_user.field_main[i][j] == "X ") // ���� �����
	{
		field_pc.field_second[i][j] = "X "; //�������� �� ������ ����� ���������
		field_user.field_main[i][j] = "Z "; //�� ����� ������ �������� ��������
		return 1;
	}
	else
	{
		field_pc.field_second[i][j] = "M "; //�������� ������
		field_user.field_main[i][j] = "M "; //�� ����� ������ �������� ���
	}
	return 0;
}