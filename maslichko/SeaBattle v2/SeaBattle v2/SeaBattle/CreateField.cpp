#include "CreateField.h"

int CreateField::Vessel(int i, int j) //1
{
	if (vessel_1 != 5)
	{
		Ship(i, j);
		vessel_1++;
		ShipPrint();

	}
	return 1;
}

int CreateField::Vessel(int i1, int j1, int i2, int j2) //2
{
	if (vessel_2 != 4)
	{
		if (i1 == i2 || j1 == j2)
		{
			Ship(i1, j1);
			Ship(i2, j2);
			vessel_2++;
			ShipPrint();
		}
	}
	return 1;
}

int CreateField::Vessel(int i1, int j1, int i2, int j2, int i3, int j3) //3
{
	if (vessel_3 != 3)
	{
		if ((i1 == i2 && i2 == i3) || (j1 == j2 && j2 == j3))
		{
			Ship(i1, j1);
			Ship(i2, j2);
			Ship(i3, j3);
			vessel_3++;
			ShipPrint();
		}
	}
	return 1;
}

int CreateField::Vessel(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4) //4
{
	if (vessel_4 != 1)
	{
		if ((i1 == i2 && i2 == i3 && i3 == i4) || (j1 == j2 && j2 == j3 && j3 == j4))
		{
			Ship(i1, j1);
			Ship(i2, j2);
			Ship(i3, j3);
			Ship(i3, j4);
			vessel_4++;
			ShipPrint();
		}
	}
	return 1;
}

void CreateField::Ship(int i, int j) //Отметка корабля
{
	field_main[i][j] = "X ";
}

void CreateField::ShipPrint() //Вывод поля при расстановке кораблей
{
	for (int q = 0; q < 11; q++)
	{
		for (int w = 0; w < 11; w++)
		{
			cout << field_main[q][w];
		}
		cout << endl;
	}
	cout << endl << endl;
}