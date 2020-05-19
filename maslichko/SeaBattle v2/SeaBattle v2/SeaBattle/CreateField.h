#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class CreateField
{
private:
	int vessel_1 = 0;
	int vessel_2 = 0;
	int vessel_3 = 0;
	int vessel_4 = 0;
	int mass[40] = { 0,0, 0,4, 0,8, 4,0, 2,2, 3,2, 2,8, 3,8, 4,5, 4,6, 6,1, 6,2,
	6,3, 6,6, 7,6, 8,6, 9,0, 9,1, 9,2, 9,3 }; //Координаты кораблей компьютера
public:
	//Поле с кораблями
	string field_main[11][11] = {
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "0"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "1"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "2"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "3"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "4"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "5"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "6"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "7"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "8"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "9"},
			{"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", " "},
	};
	//Поле с отметками ходов
	string field_second[11][11] = {
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "0"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "1"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "2"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "3"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "4"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "5"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "6"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "7"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "8"},
			{"O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "O ", "9"},
			{"0 ", "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", " "},
	};

	CreateField()
	{

	}

	CreateField(string temp)
	{
		if (temp == "pc")
		{
			Vessel(mass[0], mass[1]);
			Vessel(mass[2], mass[3]);
			Vessel(mass[4], mass[5]);
			Vessel(mass[6], mass[7]);

			Vessel(mass[8], mass[9], mass[10], mass[11]);
			Vessel(mass[12], mass[13], mass[14], mass[15]);
			Vessel(mass[16], mass[17], mass[18], mass[19]);

			Vessel(mass[20], mass[21], mass[22], mass[23], mass[24], mass[25]);
			Vessel(mass[26], mass[27], mass[28], mass[29], mass[30], mass[31]);

			Vessel(mass[32], mass[33], mass[34], mass[35], mass[36], mass[37], mass[38], mass[39]);
		}
	}

	friend ostream& operator<<(ostream& stream, const CreateField& field)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				stream << field.field_main[i][j];
			}
			stream << endl;
		}

		stream << endl << endl;

		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				stream << field.field_second[i][j];
			}
			stream << endl;
		}
		return stream;
	}
	
	int Vessel(int i, int j); //1
	int Vessel(int i1, int j1, int i2, int j2); //2
	int Vessel(int i1, int j1, int i2, int j2, int i3, int j3); //3
	int Vessel(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4); //4
	void Ship(int i, int j);
	void ShipPrint();
};

