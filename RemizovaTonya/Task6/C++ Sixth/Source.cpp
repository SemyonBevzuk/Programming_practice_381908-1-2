#include "Field.h"



int main()
{
	bool win = false, win1 = false, miss = false;
	int res = 0, x, y, ii = 0;
	int* m;
	int* s = new int[500];
	m = new int[10]{ 1,1,1,1,2,2,2,3,3,4 };

	field p, ai, empt;
	ship* aiships = new ship[10];
	ship* pships = new ship[10];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		aiships[i] = ai.gen(m[i]);
		pships[i] = p.gen(m[i]);
	}
	system("cls");
	cout << "D is 10" << endl;
	cout << "AI field" << endl;
	empt.Draw();
	cout << "Player field" << endl;
	p.Draw();
	do
	{
		do {
			do
			{
				cout << "insert coordinats" << endl << "x: ";
				cin >> x;

			} while (x < 1 || x>10);
			do
			{
				cout << "insert coordinats" << endl << "y: ";
				cin >> y;

			} while (y < 1 || y>10);

			for (int i = 0; i < 10; i++)
			{
				miss = ai.shoot(y + 1, x + 1);
				res = aiships[i].shot(x, y);
				empt.eshoot(y + 1, x + 1, miss);
				if (res == 3)
				{
					empt.dead(aiships[i].gett(), aiships[i].gets(), aiships[i].gety(), aiships[i].getx());
					ai.dead(aiships[i].gett(), aiships[i].gets(), aiships[i].gety(), aiships[i].getx());
				}
				win = p.win(aiships);

			}
			system("cls");
			cout << "D is 10" << endl;
			cout << "AI field" << endl;
			empt.Draw();
			cout << "Player field" << endl;
			p.Draw();

		} while (miss == false && win != true);

		do {
			do
			{

				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				miss = p.coincident(y + 1, x + 1);
				win1 = p.win(pships);

			} while (miss == false && win1 != true);

			s[ii] = x * 1000 + y;
			ii++;

			cout << "AI shoots at x:" << x << " y:" << y << endl;
			Sleep(2000);
			for (int i = 0; i < 10; i++)
			{
				cout << "v for" << ii;
				miss = p.shoot(y + 1, x + 1);
				res = pships[i].shot(x, y);
				p.eshoot(y + 1, x + 1, miss);
				if (res == 3)
				{
					p.dead(pships[i].gett(), pships[i].gets(), pships[i].gety(), pships[i].getx());
				}
			}
			system("cls");
			cout << "D is 10" << endl;
			cout <<  "AI field" << endl;
			empt.Draw();
			cout << "Player field" << endl;
			p.Draw();

		} while (miss == false && win1 != true);

	} while (win == false && win1 == false);

	if (win1 == true)
		cout << "AI WINS" << endl;
	if (win == true)
		cout << "Player WINS" << endl;
	delete[] m;
}