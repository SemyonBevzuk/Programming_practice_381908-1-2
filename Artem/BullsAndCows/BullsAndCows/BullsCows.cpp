#include"BullsCows.h"

Game::Game(int n) {
    if (n < 1 && n > 999999999) throw std::logic_error("Input error:wrong number!");
    int k = n;
    for (; n > 0; kol++) {
        n /= 10;
    }
    Move2Array(k, mech, kol);
}
void Game::Move2Array(int value, char ar[], int n)
{
    for (int i = kol - 1; i >= 0; i--)
    {
        ar[i] = '0' + value % 10;
        value = value / 10;
    }
}
bool Game::SameDigits(char ar[], int n)
{
    int count = 0;
    for (int i = 0; i < kol; i++)
        for (int j = i + 1; j < kol; j++)
        {
            if (ar[i] == ar[j])
                count++;
        }

    return (count != 0);
}
void Game::rand_4(char ar[], int n)
{
    Move2Array(rand() % 9999, ar, kol);
}

void Game::game1() {
    do {
        if (kol == 0) {
            srand(time(NULL));
            for (int i = 1; i < 15; i++)
                rand();
            int i = -1;
            cout << "������� ���������� ���� � ����� (�� ����� 5)" << endl;
            while (i < 1 || i > 5) {
                cin >> i;
            }
            kol = i;
            do {
                rand_4(mech, kol);
            } while (SameDigits(mech, kol));
        }
        cout << "������� ����� �� " << kol << " ���� " << endl;
        cout << "'0' - ����� �� ����" << endl;
        cin >> nOurs;
        if (nOurs == 0)
        {
            cout << "����� ����!";
            exit(0);
        }
        if (nOurs > (pow(10, kol) - 1))
        {
            cout << "�� ����� ������� ������� ����� \n";
            continue;
        }
        if (nOurs < pow(10, kol - 1))
        {
            cout << "�� ����� ������� ��������� ����� \n";
            continue;
        }
        Move2Array(nOurs, ours, kol);

        if (SameDigits(ours, kol))
        {
            cout << "������ ������� ���������� �����!";
            continue;
        }
        raz++; 
        bulls = 0; 
        cows = 0; 
        for (int i = 0; i < kol; i++)
        {
            if (mech[i] == ours[i])
                bulls++;
            for (int j = 0; j < kol; j++)
                if (mech[i] == ours[j])
                    cows++;
        }
        cows -= bulls;
        cout << "������� �" << raz << ": ����� " << bulls << "; ����� " << cows << endl;
    } while (bulls != kol);
    cout << "�� ��������!!!" << endl;
    cout << "1-������ �����" << endl;
    cout << "2-�����" << endl;
    int v = -1;
    while (v < 1 || v > 2) {
        cin >> v;
    }
    switch (v) {
    case 1:
        kol = 0;
        game1();  break;
    case 2:
        exit(0);  break;
    };
}