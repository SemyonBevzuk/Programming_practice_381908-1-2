#include "Cinema.h"


int Cinema::PriceChange(int hour, int price)
{
	if (hour > 7 && hour < 12) //Утренний 
	{
		price = price * 0.75;
	}
	else if (hour > 11 && hour < 18) //Дневной
	{
		price = price;
	}
	else if (hour > 17 && hour <= 23) //Вечерний
	{
		price = price * 1.5;
	}
	return price;
}

int Cinema::Places(int room, int places)
{
	if (room == 1)
	{
		places = 80;
		pls.resize(8);
		for (int i = 0; i < 8; i++)
		{
			pls[i].resize(10);
			for (int j = 0; j < 10; j++)
			{
				pls[i][j] = "free";
			}
		}
	}
	else if (room == 2)
	{
		places = 100;
		pls.resize(10);
		for (int i = 0; i < 10; i++)
		{
			pls[i].resize(10);
			for (int j = 0; j < 10; j++)
			{
				pls[i][j] = "free";
			}
		}
	}
	return places;
}